import unittest

MEMOIZATION = [0] * 20


def fibonacci(num):
    if num == 0:
        return 0
    if num <= 2:
        return 1
    if MEMOIZATION[num] != 0:
        return MEMOIZATION[num]

    MEMOIZATION[num] = fibonacci(num - 1) + fibonacci(num - 2)

    return MEMOIZATION[num]


class TestFibonacciWithRecursion(unittest.TestCase):
    def test_should_return_1_when_given_num_is_1(self):
        self.assertEqual(fibonacci(1), 1)

    def test_should_return_1_when_given_num_is_2(self):
        self.assertEqual(fibonacci(2), 1)

    def test_should_return_2_when_given_num_is_3(self):
        self.assertEqual(fibonacci(3), 2)

    def test_should_return_3_when_given_num_is_4(self):
        self.assertEqual(fibonacci(4), 3)

    def test_should_return_55_when_given_num_is_10(self):
        self.assertEqual(fibonacci(10), 55)

    def test_should_return_0_when_given_num_is_0(self):
        self.assertEqual(fibonacci(0), 0)
