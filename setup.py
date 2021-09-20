import sys

from glob import glob
from setuptools import setup, find_packages
from pybind11.setup_helpers import Pybind11Extension, build_ext

pkg_name = 'pyblossom'
__version__ = "0.1"

ext_modules = [
    Pybind11Extension(
        pkg_name + "._cpp",
        include_dirs = ['./src'],
        sources = sorted(glob("src/*.cxx")),
        # Example: passing in the version to the compiled code
        define_macros = [('VERSION_INFO', __version__)],
    ),
]

setup(
    name="pyblossom",
    version=__version__,
    author="Davide Anastasia",
    author_email="davide.anastasia@gmail.com",
    description="a minimal example package (with pybind11)",
    ext_modules=ext_modules,
    extras_require={"test": "pytest"},
    cmdclass={"build_ext": build_ext},
    test_suite='tests',
    packages=['pyblossom'],
    zip_safe=False
)