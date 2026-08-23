"""
Find the LibXC shared object and imports it as core.
"""

import ctypes
import ctypes.util
import os
import sys
import sysconfig

# Attempt to load the compiled C code
core = None
__libxc_path = None


def _load_library(libname, loader_path):
    """Lifted from numpy.ctypeslib"""
    libname = os.fsdecode(libname)
    loader_path = os.fsdecode(loader_path)
    ext = os.path.splitext(libname)[1]
    if not ext:
        import sys
        import sysconfig
        base_ext = ".so"
        if sys.platform.startswith("darwin"):
            base_ext = ".dylib"
        elif sys.platform.startswith("win"):
            base_ext = ".dll"
        libname_ext = [libname + base_ext]
        so_ext = sysconfig.get_config_var("EXT_SUFFIX")
        if not so_ext == base_ext:
            libname_ext.insert(0, libname + so_ext)
    else:
        libname_ext = [libname]

    loader_path = os.path.abspath(loader_path)
    if not os.path.isdir(loader_path):
        libdir = os.path.dirname(loader_path)
    else:
        libdir = loader_path

    for ln in libname_ext:
        libpath = os.path.join(libdir, ln)
        if os.path.exists(libpath):
            try:
                return ctypes.cdll[libpath]
            except OSError:
                # defective lib file
                raise
    raise OSError("no file with expected extension")


# First check the local folder
try:
    __libxc_path = os.path.abspath(os.path.dirname(__file__))
    core = _load_library("libxc", __libxc_path)
except OSError:
    # If no libxc is local, check LD_LIBRARY_PATHS's
    __libxc_path = ctypes.util.find_library("xc")

    # If we still havent found it, give up and throw an error
    if __libxc_path is None:
        raise ImportError(
            "LibXC Shared object not found, searched Python module local directory and library paths"
        )

    # Load the C object
    core = ctypes.CDLL(__libxc_path)


def get_core_path():
    """
    Returns the path of the loaded LibXC shared object.
    """

    return __libxc_path
