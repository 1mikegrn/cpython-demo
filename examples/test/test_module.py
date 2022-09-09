import numpy as np

from args_kwargs import args_sum
from numpy_utils import np_iter, np_create

class TestModule:
    def test_args_kwargs(self):
        assert args_sum(1,2,3) == 6
        assert args_sum(1,2,3,4.5) == 10.5

    def test_numpy_utils(self):
        arr = np.array([1.1,2.2,3.3])
        assert np_iter(arr) == 6.6

    def test_create(self):
        arr = np_create(1,2,3,4)
        assert type(arr) == np.ndarray
        assert arr.shape == (2,2)
