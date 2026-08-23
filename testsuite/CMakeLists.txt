link_libraries(xc)
add_executable(xc-get_data xc-get_data.c)

if(ENABLE_CUDA)
  set_source_files_properties(xc-get_data.c PROPERTIES LANGUAGE CUDA)
  set(XC_TEST_FLAGS "XC_FLAGS_ON_DEVICE" CACHE STRING "Flags that are passed to functional initialization")
elseif(ENABLE_HIP)
  set_source_files_properties(xc-get_data.c PROPERTIES LANGUAGE HIP)
  set(XC_TEST_FLAGS "XC_FLAGS_ON_DEVICE" CACHE STRING "Flags that are passed to functional initialization")
else()
  set_target_properties(xc-get_data PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
  set(XC_TEST_FLAGS "XC_FLAGS_ON_HOST" CACHE STRING "Flags that are passed to functional initialization")
endif()

if(BUILD_SHARED_LIBS)
# One ctest test per regression family, rather than a single opaque
# "python-tests". As one test the suite reported a bare pass/fail line after
# a couple of minutes, told you nothing on success (--output-on-failure only
# prints failures), dumped the whole suite at you on failure, and could not
# use `ctest -j` at all -- it sat serial while every other test had finished.
#
# Split by directory, which needs no pytest collection at configure time (the
# library is not built yet then, so pylibxc could not even be imported).
file(GLOB _xc_regression_dirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     ${CMAKE_CURRENT_SOURCE_DIR}/regression/*)
set(_xc_pytest_names "")
foreach(_d IN LISTS _xc_regression_dirs)
  if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${_d})
    string(REPLACE "regression/" "" _fam ${_d})
    add_test(NAME python-${_fam}
      COMMAND ${PYTHON_EXECUTABLE} xc-run_pytest ${_d}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
    list(APPEND _xc_pytest_names python-${_fam})
  endif()
endforeach()

# Everything that is not a regression family: the API/util tests, the atomic
# suite, and the code-generation invariants.
add_test(NAME python-general COMMAND ${PYTHON_EXECUTABLE} xc-run_pytest general
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
# The atomic tier is marked "atomic" and deselected by default -- it costs
# ~20 minutes -- so it is deliberately not registered here. Run it with
#   pytest -m atomic testsuite/atomic
add_test(NAME python-codegen COMMAND ${PYTHON_EXECUTABLE} xc-run_pytest
  test_codegen_determinism.py test_codegen_jet_arrays.py test_math_utilities.py
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND _xc_pytest_names python-general python-codegen)

if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.22)
  # ENVIRONMENT_MODIFICATION prepends rather than replaces, and uses the
  # platform's own list separator -- ":" on Unix, ";" on Windows. It also lets
  # us point at $<TARGET_FILE_DIR:xc>, which is the only way to name the
  # library directory under a multi-config generator: Visual Studio puts the
  # DLL in <build>/Debug, not <build>.
  #
  # PATH is what matters on Windows (LD_LIBRARY_PATH means nothing there):
  # pylibxc looks for a module-local libxc.dll and then falls back to
  # find_library("xc"), which searches PATH.
  set_tests_properties(${_xc_pytest_names} PROPERTIES
    ENVIRONMENT_MODIFICATION
      "PYTHONPATH=path_list_prepend:${PROJECT_SOURCE_DIR};LD_LIBRARY_PATH=path_list_prepend:$<TARGET_FILE_DIR:xc>;DYLD_LIBRARY_PATH=path_list_prepend:$<TARGET_FILE_DIR:xc>;PATH=path_list_prepend:$<TARGET_FILE_DIR:xc>"
    ENVIRONMENT "XC_TEST_FLAGS=${XC_TEST_FLAGS}")
else()
  set_tests_properties(${_xc_pytest_names}
      PROPERTIES ENVIRONMENT "PYTHONPATH=${PROJECT_SOURCE_DIR}:$ENV{PYTHONPATH};LD_LIBRARY_PATH=${PROJECT_BINARY_DIR}:$ENV{LD_LIBRARY_PATH};XC_TEST_FLAGS=${XC_TEST_FLAGS}")
endif()
endif()

# Host-side C unit tests: special-function accuracy + the public API.
# Skipped on CUDA/HIP builds, which exercise functional values through the
# pytest suite (with XC_FLAGS_ON_HOST) instead.
if(NOT ENABLE_CUDA AND NOT ENABLE_HIP)
  add_executable(xc-special-functions xc-special-functions.c)
  add_executable(xc-api xc-api.c)
  add_executable(xc-distinct xc-distinct.c)
  set_target_properties(xc-special-functions xc-api xc-distinct
    PROPERTIES C_STANDARD 99 C_STANDARD_REQUIRED ON C_EXTENSIONS OFF)
  target_include_directories(xc-special-functions PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
  add_test(NAME special-functions COMMAND xc-special-functions)
  add_test(NAME api COMMAND xc-api)
  add_test(NAME distinct COMMAND xc-distinct)
  if(BUILD_SHARED_LIBS)
    if(CMAKE_VERSION VERSION_GREATER_EQUAL 3.22)
      set_tests_properties(special-functions api distinct PROPERTIES
        ENVIRONMENT_MODIFICATION
          "LD_LIBRARY_PATH=path_list_prepend:$<TARGET_FILE_DIR:xc>;DYLD_LIBRARY_PATH=path_list_prepend:$<TARGET_FILE_DIR:xc>;PATH=path_list_prepend:$<TARGET_FILE_DIR:xc>")
    else()
      set_tests_properties(special-functions api distinct
        PROPERTIES ENVIRONMENT "LD_LIBRARY_PATH=${PROJECT_BINARY_DIR}:$ENV{LD_LIBRARY_PATH}")
    endif()
  endif()
endif()

# ctest's default timeout is 1500 s but the AppVeyor images report an
# effectively infinite one (9999826 s), so a wedged test burns the whole CI
# budget instead of failing. That is not hypothetical: a Debug MSVC build sat
# in special-functions for 54 minutes, a test that takes 0.00 s on Linux --
# on Windows an assertion or access violation in a Debug build raises a modal
# error dialog, and with nobody to dismiss it the process simply waits.
#
# Bound every test. These are generous next to the real numbers (the python
# suite is about a minute; the C tests are instantaneous) and only ever fire
# on a hang.
set(_xc_c_tests special-functions api distinct)
foreach(_t IN LISTS _xc_c_tests)
  if(TEST ${_t})
    set_tests_properties(${_t} PROPERTIES TIMEOUT 300)
  endif()
endforeach()
foreach(_t IN LISTS _xc_pytest_names)
  set_tests_properties(${_t} PROPERTIES TIMEOUT 1800)
endforeach()
