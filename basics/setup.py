import os.path
from setuptools import find_packages, setup, Extension

HERE = os.path.abspath(os.path.dirname(__file__))

extensions = [
    Extension(
        'hello_world',
        [os.path.join('src', 'hello_world.c')]
    )
]

setup(
    name="hello_world",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    include_package_data=True,
    ext_modules=extensions
)
