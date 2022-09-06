import os.path
from setuptools import find_packages, setup, Extension

import numpy as np

extensions = [
    Extension(
        name='args_kwargs',
        sources=[os.path.join('src', 'args_kwargs.c')],
    ),
    Extension(
        name='numpy_utils',
        sources=[os.path.join('src', 'numpy_utils.c')],
        include_dirs=[np.get_include()]
    ),
]

setup(
    name="examples",
    packages=find_packages(where="src"),
    package_dir={"": "src"},
    include_package_data=True,
    ext_modules=extensions
)

