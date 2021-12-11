from distutils.core import setup, Extension

module = Extension(
    "medicalcheck",
    sources=["wrapper.c", "medicalcheck.c"]
)

setup(
    name="medicalcheck",
    version="1.0.0",
    ext_modules=[module]
)