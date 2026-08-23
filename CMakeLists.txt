cmake_minimum_required(VERSION 3.21)
cmake_policy(SET CMP0048 NEW)   # project_VERSION* variables populated from project(... VERSION x.x.x) string
if(POLICY CMP0148)
  cmake_policy(SET CMP0148 OLD) # The FindPythonInterp and FindPythonLibs modules are removed in CMake 3.27
endif()
if(POLICY CMP0104)
  cmake_policy(SET CMP0104 OLD) # Don't initialize CMAKE_CUDA_ARCHITECTURES when CMAKE_CUDA_COMPILER_ID is NVIDIA. Empty CUDA_ARCHITECTURES is allowed.
endif()
project(Libxc
  LANGUAGES C)
set(Libxc_AUTHORS      "Miguel A.L. Marques and others")
set(Libxc_DESCRIPTION  "Exchange-correlation functionals for density-functional theory")
set(Libxc_EMAIL        "https://gitlab.com/libxc/libxc/")
set(Libxc_URL          "https://libxc.gitlab.io/")
set(Libxc_LICENSE      "Mozilla Public License, version 2.0 (MPL-2.0)")

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

if(ENABLE_CUDA)
  if(ENABLE_HIP)
    message(FATAL_ERROR "Can only enable either CUDA or HIP, not both")
  endif()
  enable_language(CUDA)
endif()

if(ENABLE_HIP)
  enable_language(HIP)
endif()

# Loaded early so install-directory variables (CMAKE_INSTALL_INCLUDEDIR
# etc.) are available when option defaults are computed below.
include(GNUInstallDirs)

################################### Options ####################################
include(psi4OptionsTools)
option_with_default(CMAKE_BUILD_TYPE "Build type" Release)
option_with_print(BUILD_SHARED_LIBS "Build final library as shared, not static. For Windows, also add CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS=ON" ON)
# Test only if libXC is built directly and not as a dependency of something else
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  option_with_print(BUILD_TESTING "Compile the testing infrastructure" ON)
else()
  set(BUILD_TESTING OFF)
endif()
option_with_default(BUILD_FPIC "Libraries will be compiled with position independent code" ON)
if((${BUILD_SHARED_LIBS}) AND NOT ${BUILD_FPIC})
  message(FATAL_ERROR "BUILD_SHARED_LIBS ON and BUILD_FPIC OFF are incompatible, as shared library requires position independent code")
endif()
option_with_default(NAMESPACE_INSTALL_INCLUDEDIR "Location within CMAKE_INSTALL_INCLUDEDIR to which headers are installed (e.g., /libxc)" /)
option_with_print(ENABLE_FORTRAN "Build Fortran 2003 interface" OFF)
option_with_default(FORTRAN_MODULE_INSTALL_DIR "Install location for Fortran .mod files (defaults to the header install dir, matching --with-custom-fmoddir from Autotools)" "${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR}")
option_with_print(ENABLE_PYTHON "Install Python API interface" OFF)
if(${ENABLE_PYTHON} AND NOT ${BUILD_SHARED_LIBS})
  message(FATAL_ERROR "ENABLE_PYTHON ON requires BUILD_SHARED_LIBS ON because only shared libraries can be dynamically loaded")
endif()
# Highest derivative order compiled into the library:
#   0 = energy (exc) only, 1 = +vxc, 2 = +fxc, 3 = +kxc, 4 = +lxc.
set(MAXORDER 2 CACHE STRING "Highest derivative order to build (0..4)")
# Deprecated per-order switches, kept as aliases for one release. Pre-7.1 these
# were the primary control and the built order was the highest one NOT disabled.
# Reproduce that: if any truthy -DDISABLE_<ORDER> is given, derive MAXORDER from
# the disabled orders (starting from the full order 4), overriding the default --
# so e.g. -DDISABLE_LXC=ON gives 3, and -DDISABLE_KXC=OFF -DDISABLE_LXC=ON gives 3.
set(_maxorder 4)
set(_dep_used FALSE)
foreach(_dep "LXC;3" "KXC;2" "FXC;1" "VXC;0")
  list(GET _dep 0 _o)
  list(GET _dep 1 _cap)
  if(DEFINED DISABLE_${_o} AND DISABLE_${_o})
    set(_dep_used TRUE)
    if(_maxorder GREATER ${_cap})
      set(_maxorder ${_cap})
    endif()
  endif()
endforeach()
if(_dep_used)
  message(DEPRECATION "DISABLE_*XC are deprecated; use -DMAXORDER=${_maxorder}")
  set(MAXORDER ${_maxorder})
endif()
message(STATUS "MAXORDER: ${MAXORDER}")
add_compile_definitions(XC_MAXORDER=${MAXORDER})
option_with_print(DISABLE_FHC "Disable enforcement of Fermi hole curvature?" OFF)
option_with_print(XC_CHECK_NUMERICS "Check functional outputs for NaN/Inf and (where supported) trap FPEs during evaluation" OFF)
option_with_print(XC_PROFILING "Enable additional profiling code" OFF)

######################### Process & Validate Options ###########################
include(autocmake_safeguards)

################################# Main Project #################################
include(CMakePackageConfigHelpers)

set(PN ${PROJECT_NAME})

# link -lm only if necessary
find_package(StandardMathLibraryC)
# check if cbrt exists and declare HAVE_CBRT if it does
check_c_source_compiles (
  "#include <math.h>
int main() {
  return (int)(cbrt(0.8));
}" HAVE_CBRT)
if (HAVE_CBRT)
  add_definitions (-DHAVE_CBRT)
endif (HAVE_CBRT)

# check if feenableexcept exists (GNU extension, used by optional FPE
# trapping in work_*_inc.c) and declare HAVE_FEENABLEEXCEPT if it does
set(CMAKE_REQUIRED_LIBRARIES_BACKUP "${CMAKE_REQUIRED_LIBRARIES}")
list(APPEND CMAKE_REQUIRED_LIBRARIES ${STANDARD_MATH_LIBRARY})
check_c_source_compiles (
  "#define _GNU_SOURCE 1
#include <fenv.h>
int main() {
  return feenableexcept(0);
}" HAVE_FEENABLEEXCEPT)
set(CMAKE_REQUIRED_LIBRARIES "${CMAKE_REQUIRED_LIBRARIES_BACKUP}")
if (HAVE_FEENABLEEXCEPT)
  add_definitions (-DHAVE_FEENABLEEXCEPT)
endif (HAVE_FEENABLEEXCEPT)

# <<<  Build  >>>

# extract project version from source
file(STRINGS "configure.ac" _libxc_configure_ac
     REGEX "AC_INIT")
foreach(ver ${_libxc_configure_ac})
    if (ver MATCHES "^AC_INIT..libxc...([0-9]+).([0-9]+).([0-9]+).*$")
        set(PROJECT_VERSION_MAJOR ${CMAKE_MATCH_1})
        set(PROJECT_VERSION_MINOR ${CMAKE_MATCH_2})
        set(PROJECT_VERSION_MICRO ${CMAKE_MATCH_3})
    endif()
endforeach()

set(PROJECT_VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_MICRO})
message(STATUS "Version: Full ${PROJECT_VERSION}")

# repurpose xc_version from Make for CMake
set(VERSION ${PROJECT_VERSION})
set(XC_MAJOR_VERSION ${PROJECT_VERSION_MAJOR})
set(XC_MINOR_VERSION ${PROJECT_VERSION_MINOR})
set(XC_MICRO_VERSION ${PROJECT_VERSION_MICRO})
configure_file(xc_version.h.in xc_version.h @ONLY)

# create dummy config.h
configure_file(config.h.cmake.in config.h @ONLY)

# special substitutions for pkgconfig files
include(JoinPaths)
join_paths(libdir_for_pc_file "\${exec_prefix}" "${CMAKE_INSTALL_LIBDIR}")
join_paths(includedir_for_pc_file "\${prefix}" "${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR}")
configure_file(cmake/libxc.pc.in libxc.pc @ONLY)

# extract project soversion from source
file(STRINGS "configure.ac" _libxc_configure_ac
  REGEX "XC_(CURRENT|REVISION|AGE)=")
foreach(ver ${_libxc_configure_ac})
  if (ver MATCHES "XC_(CURRENT|REVISION|AGE)=+([^ ]+)$")
    set(XC_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
  endif()
endforeach()
set(${PROJECT_NAME}_SOVERSION ${XC_CURRENT}:${XC_REVISION}:${XC_AGE})
math(EXPR ${PROJECT_NAME}_SOMAJOR "${XC_CURRENT} - ${XC_AGE}")
message(STATUS "SO Version: Full ${${PROJECT_NAME}_SOVERSION} Major ${${PROJECT_NAME}_SOMAJOR}")

file(READ "src/sources.mk" _sources_mk)
string(REGEX MATCHALL "[a-z_0-9][a-z_0-9]*\\.c" raw_sources_list "${_sources_mk}")

set(src_prefix "src/")
string(REGEX REPLACE "([^;]+)" "${src_prefix}\\1" sources_list "${raw_sources_list}")

# Derivative-order compile gating is driven by MAXORDER (the global
# XC_MAXORDER definition set above).
if(NOT DISABLE_FHC)
  add_compile_definitions(XC_ENFORCE_FERMI_HOLE_CURVATURE)
endif()

if(ENABLE_CUDA)
  set_source_files_properties(${sources_list} PROPERTIES LANGUAGE CUDA)
elseif(ENABLE_HIP)
  set_source_files_properties(${sources_list} PROPERTIES LANGUAGE HIP)
endif()

set(raw_sources_list_f90
  src/libxc_master.F90
  )

# when headers namespaced, xc_version include in xc.h needs to be local, not
#   system to be found
file(READ ${src_prefix}xc.h _src_contents)
string(REPLACE "<xc_version.h>" "\"xc_version.h\"" _quoted_src "${_src_contents}")
file(WRITE ${PROJECT_BINARY_DIR}/${src_prefix}xc.h "${_quoted_src}")

# provide basic installed rpath, so Fortran lib can find C lib
if (APPLE)
    set(base "@loader_path")
else()
    set(base "$ORIGIN")
endif()
file(RELATIVE_PATH relDir ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
                          ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_INSTALL_RPATH ${base} ${base}/${relDir})

# STATIC/SHARED on below governed by BUILD_SHARED_LIBS
add_library(xc ${sources_list})
get_target_property(XC_TARGET_TYPE xc TYPE)
if(ENABLE_CUDA)
  set_target_properties(xc PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
  if(XC_PROFILING)
    find_package(CUDAToolkit REQUIRED)
    target_link_libraries(xc PRIVATE CUDA::nvtx3)
  endif()
elseif(ENABLE_HIP)
  # clang replaces pow()/exp() with the llvm.pow.f64/llvm.exp.f64 intrinsics,
  # but with -fgpu-rdc the amdgcn ISA is generated at link time, where the
  # AMDGPULibCalls pass that would lower them to __ocml_*_f64 no longer runs, so
  # lld aborts with "Cannot select fpow" / "no libcall available for fexp".
  # -fno-builtin-pow/-fno-builtin-exp keep pow()/exp() as ordinary calls that
  # resolve to the HIP __device__ overloads (OCML) instead of the intrinsics,
  # while leaving sqrt() etc. as native amdgcn ops. (-fmath-errno would instead
  # force host-libm libcalls -- sqrt/sqrtl/powl/expl -- that the GPU has no
  # implementation for.)
  target_compile_options(xc PRIVATE
    $<$<COMPILE_LANGUAGE:HIP>:-fgpu-rdc>
    $<$<COMPILE_LANGUAGE:HIP>:-fno-builtin-pow>
    $<$<COMPILE_LANGUAGE:HIP>:-fno-builtin-exp>)
  if(XC_TARGET_TYPE STREQUAL STATIC_LIBRARY)
    target_link_options(xc PUBLIC $<$<LINK_LANGUAGE:HIP>:-fgpu-rdc --hip-link>)
  else()
    target_link_options(xc PRIVATE $<$<LINK_LANGUAGE:HIP>:-fgpu-rdc --hip-link>)
  endif()
  if(XC_PROFILING)
    find_package(rocprofiler-sdk-roctx REQUIRED)
    target_link_libraries(xc PRIVATE rocprofiler-sdk-roctx::rocprofiler-sdk-roctx)
  endif()
else()
  set_target_properties(xc PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
endif()
# 32-bit x86 defaults to 387 math, which keeps intermediates in 80-bit
# registers and rounds them on spill. Results then depend on register
# allocation rather than on the arithmetic: on i686 the regression suite misses
# gga_x_hjs_pbe's v2sigma2 by 2x its tolerance and mgga_x_2d_prhg07_prp10's
# v2rho2 by 2000x. Since the library's premise is accuracy to floating-point
# precision whatever the compiler, ask for SSE2 instead, which is what every
# 64-bit target already uses.
#
# -fexcess-precision=standard would fix the semantics without requiring SSE2,
# but it makes GCC pathological on the larger generated kernels: gga_x_wpbeh.c
# alone did not finish compiling in 46 minutes, against roughly 5 for the whole
# library otherwise.
#
# The cost is a Pentium 4 / Athlon 64 baseline on 32-bit x86 only. Nothing else
# is touched: x86-64 already implies SSE2, and other architectures never take
# this branch.
if(CMAKE_SIZEOF_VOID_P EQUAL 4
   AND CMAKE_SYSTEM_PROCESSOR MATCHES "^(i[3-6]86|x86)$"
   AND (CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID MATCHES "Clang"))
  include(CheckCCompilerFlag)
  check_c_compiler_flag("-msse2 -mfpmath=sse" XC_HAVE_SSE_MATH)
  if(XC_HAVE_SSE_MATH)
    target_compile_options(xc PRIVATE -msse2 -mfpmath=sse)
    message(STATUS "32-bit x86: using SSE2 math (-msse2 -mfpmath=sse) instead of 387")
  else()
    message(WARNING
      "32-bit x86 without SSE2 support: x87 excess precision will make some "
      "second derivatives disagree with the reference values.")
  endif()
endif()

target_link_libraries(xc PUBLIC ${STANDARD_MATH_LIBRARY})
set_target_properties(xc PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC}
  SOVERSION ${${PROJECT_NAME}_SOMAJOR})
if(${BUILD_SHARED_LIBS})
  target_link_libraries(xc PRIVATE ${LIBC_INTERJECT})
  if(APPLE)
    set_target_properties(xc PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
  endif()
endif()

if(ENABLE_FORTRAN)
  enable_language(Fortran)
  add_library(xcf03 ${raw_sources_list_f90})
  target_link_libraries(xcf03 xc)
  set_target_properties(xcf03 PROPERTIES POSITION_INDEPENDENT_CODE ${BUILD_FPIC}
    SOVERSION ${${PROJECT_NAME}_SOMAJOR})
  if(ENABLE_CUDA)
    set_target_properties(xcf03 PROPERTIES CUDA_SEPARABLE_COMPILATION ON)
  endif()
endif()

add_executable(xc-info "${src_prefix}/xc-info.c")
if(ENABLE_CUDA)
  set_source_files_properties("${src_prefix}/xc-info.c" PROPERTIES LANGUAGE CUDA)
elseif(ENABLE_HIP)
  set_source_files_properties("${src_prefix}/xc-info.c" PROPERTIES LANGUAGE HIP)
else()
  set_target_properties(xc-info PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
endif()
target_link_libraries(xc-info xc)

add_executable(xc-threshold "${src_prefix}/xc-threshold.c")
if(ENABLE_CUDA)
  set_source_files_properties("${src_prefix}/xc-threshold.c" PROPERTIES LANGUAGE CUDA)
elseif(ENABLE_HIP)
  set_source_files_properties("${src_prefix}/xc-threshold.c" PROPERTIES LANGUAGE HIP)
else()
  set_target_properties(xc-threshold PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
endif()
target_link_libraries(xc-threshold xc)

add_executable(xc-sanity "${src_prefix}/xc-sanity.c")
if(ENABLE_CUDA)
  set_source_files_properties("${src_prefix}/xc-sanity.c" PROPERTIES LANGUAGE CUDA)
elseif(ENABLE_HIP)
  set_source_files_properties("${src_prefix}/xc-sanity.c" PROPERTIES LANGUAGE HIP)
else()
  set_target_properties(xc-sanity PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
endif()
target_link_libraries(xc-sanity xc)

add_executable(genwiki "${src_prefix}/genwiki.c")
if(ENABLE_CUDA)
  set_source_files_properties("${src_prefix}/genwiki.c" PROPERTIES LANGUAGE CUDA)
elseif(ENABLE_HIP)
  set_source_files_properties("${src_prefix}/genwiki.c" PROPERTIES LANGUAGE HIP)
else()
  set_target_properties(genwiki PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
endif()
target_link_libraries(genwiki xc)


include_directories(${PROJECT_SOURCE_DIR}/${src_prefix}  # for util.h
  ${PROJECT_BINARY_DIR}/${src_prefix}  # for xc.h
  ${PROJECT_BINARY_DIR}  # for xc_version.h, config.h
)

if(BUILD_TESTING)
  find_package(PythonInterp REQUIRED)
  execute_process(
    COMMAND ${PYTHON_EXECUTABLE} -m pytest --version
    RESULT_VARIABLE status)
  if(NOT status EQUAL 0)
    message(FATAL_ERROR "Pytest not found")
  endif()
  set(CMAKE_CTEST_ARGUMENTS "-V")
  enable_testing ()
  add_subdirectory(testsuite)
endif()

add_subdirectory(examples)

# Developer targets to regenerate bookkeeping files from the Maple sources
# and BibTeX bibliography. These write into the source tree and are not
# part of the default build; invoke explicitly with e.g. `make funcs` /
# `make references`. Mirrors the Autotools targets in src/Makefile.am
# and Makefile.am. Only created if a Python 3 interpreter is found.
find_package(Python3 COMPONENTS Interpreter QUIET)
if(Python3_Interpreter_FOUND)
  add_custom_target(funcs
    COMMAND ${Python3_EXECUTABLE} ${PROJECT_SOURCE_DIR}/scripts/get_functional_info.py --srcdir=${PROJECT_SOURCE_DIR}/src
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src
    COMMENT "Regenerating functional registry files from Maple sources"
    VERBATIM)

  add_custom_target(references
    COMMAND ${Python3_EXECUTABLE} ${PROJECT_SOURCE_DIR}/scripts/get_references.py ${PROJECT_SOURCE_DIR}/libxc.bib
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/src
    COMMENT "Regenerating references.c/references.h from libxc.bib"
    VERBATIM)

  # Regenerate every src/maple2c/*.c file from the SymPy math definitions
  # under python/. SymPy-pipeline counterpart of the per-family `maple2c`
  # targets in maple/*/Makefile.am. Override the derivative order with
  # -DSYMPY2C_MAXORDER=<n> (default 4).
  set(SYMPY2C_MAXORDER 4 CACHE STRING
      "Highest derivative order generated by the sympy2c target")
  add_custom_target(sympy2c
    COMMAND ${Python3_EXECUTABLE} ${PROJECT_SOURCE_DIR}/scripts/sympy2c/compile.py
            --all --maxorder ${SYMPY2C_MAXORDER}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Regenerating src/maple2c/*.c from the SymPy definitions under python/"
    VERBATIM)
endif()

# <<<  Install  >>>

# by default, headers NOT namespace protected
install(FILES ${PROJECT_BINARY_DIR}/${src_prefix}/xc.h
  ${PROJECT_SOURCE_DIR}/${src_prefix}/xc_funcs.h
  ${PROJECT_SOURCE_DIR}/${src_prefix}/xc_funcs_worker.h
  ${PROJECT_SOURCE_DIR}/${src_prefix}/xc_funcs_removed.h
  ${PROJECT_BINARY_DIR}/xc_version.h
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR})
install(TARGETS xc-info
  OPTIONAL
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
install(TARGETS xc
  EXPORT c_interface
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR})

if(ENABLE_FORTRAN)
  configure_file(cmake/libxcf03.pc.in libxcf03.pc @ONLY)
  install(TARGETS xc xcf03
    EXPORT f_interface
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR})
  install(FILES "${PROJECT_BINARY_DIR}/xc_f03_lib_m.mod" "${PROJECT_BINARY_DIR}/xc_f03_funcs_m.mod"
    DESTINATION ${FORTRAN_MODULE_INSTALL_DIR})
  if(NOT MSVC)
    install(FILES ${PROJECT_BINARY_DIR}/libxcf03.pc
      DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig/)
  endif()
endif()

# <<<  Export Interface  >>>

target_compile_definitions(xc INTERFACE USING_${PN})
target_include_directories(xc INTERFACE
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}${NAMESPACE_INSTALL_INCLUDEDIR}>)

# <<<  Export Config  >>>

set(CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PN}")
configure_package_config_file(cmake/${PN}Config.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake"
  INSTALL_DESTINATION ${CMAKECONFIG_INSTALL_DIR})
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
  VERSION ${${PN}_VERSION}
  COMPATIBILITY SameMajorVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PN}Config.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/${PN}ConfigVersion.cmake
  DESTINATION ${CMAKECONFIG_INSTALL_DIR})
install(EXPORT c_interface
  NAMESPACE "${PN}::"
  FILE "${PN}Targets-C.cmake"
  DESTINATION ${CMAKECONFIG_INSTALL_DIR})

if(ENABLE_FORTRAN)
    install(EXPORT f_interface
      NAMESPACE "${PN}::"
      FILE "${PN}Targets-Fortran.cmake"
      DESTINATION ${CMAKECONFIG_INSTALL_DIR})
endif()

if(ENABLE_PYTHON)
  set(SOURCE_PYTHON_API
    pylibxc/__init__.py
    pylibxc/array_backend.py
    pylibxc/core.py
    pylibxc/dlpack.py
    pylibxc/flags.py
    pylibxc/functional.py
    pylibxc/structs.py
    pylibxc/testing.py
    pylibxc/util.py
    pylibxc/version.py
    pylibxc/example_densities.py
  )
  install(
    FILES ${SOURCE_PYTHON_API}
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pylibxc
  )
  if(UNIX)
    install(CODE "execute_process(COMMAND ${CMAKE_COMMAND} -E create_symlink \
      ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/libxc.so.${${PROJECT_NAME}_SOMAJOR} \
      ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}/pylibxc/libxc.so)")
  endif()
endif()

export(EXPORT c_interface
    NAMESPACE "${PN}::"
    FILE "${PROJECT_BINARY_DIR}/${PN}Targets.cmake")

if(NOT MSVC)
  install(FILES ${PROJECT_BINARY_DIR}/libxc.pc
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig/)
endif()
