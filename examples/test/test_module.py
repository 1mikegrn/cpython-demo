import numpy as np

from args_kwargs import args_sum
from numpy_utils import np_iter

class TestModule:
    def test_args_kwargs(self):
        assert args_sum(1,2,3) == 6
        assert args_sum(1,2,3,4.5) == 10.5

    def test_numpy_utils(self):
        arr = np.array([1.1,2.2,3.3])
        np_iter(arr)
