import unittest


def tribonacci(signature, n):
    list_tribonacci = signature
    if n < 4:
        return signature[:n]
    else:
        for i in range(3, n):
            list_tribonacci.append(sum(list_tribonacci[-3:]))
        return list_tribonacci


class TestTribonacci(unittest.TestCase):
    def test_signature_is_111(self):
        self.assertEqual(tribonacci([1, 1, 1], 10), [1, 1, 1, 3, 5, 9, 17, 31, 57, 105])

    def test_signature_is_000(self):
        self.assertEqual(tribonacci([0, 0, 0], 10), [0, 0, 0, 0, 0, 0, 0, 0, 0, 0])

    def test_when_n_is_1(self):
        self.assertEqual(tribonacci([1, 1, 1], 1), [1])

    def test_when_n_is_0(self):
        self.assertEqual(tribonacci([300, 200, 100], 0), [])