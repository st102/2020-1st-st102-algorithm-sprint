import unittest


def tribonacci(signature, n):
    tribonaccilist = []
    for i in range(n):
        if i == 0 or i == 1 or i == 2:
            tribonaccilist.append(signature[i])
        else:
            tribonaccilist.append(tribonaccilist[i - 1] + tribonaccilist[i - 2] + tribonaccilist[i - 3])
    return tribonaccilist


class TestTribonacci(unittest.TestCase):
    def test_tribonacci(self):
        self.assertEqual(tribonacci([1, 1, 1], 10), [1, 1, 1, 3, 5, 9, 17, 31, 57, 105])


if __name__ == '__main__':
    unittest.main()