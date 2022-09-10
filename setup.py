from setuptools import find_packages
from skbuild import setup

setup(
    name="emblem",
    version="1.0",
    description="A Game Engine",
    author="Darren Eberly",
    license="MIT",
    include_package_data=True,
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    cmake_install_dir="src/emblem",
    python_requires=">=3.9",
)
