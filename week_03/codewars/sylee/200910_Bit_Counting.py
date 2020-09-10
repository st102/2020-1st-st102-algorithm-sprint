import unittest


def count_bits(n):
    return sum(int(x) for x in bin(n)[2:])


class TestCountBits(unittest.TestCase):
    def test_bit(self):
        self.assertEqual(count_bits(0), 0)
        self.assertEqual(count_bits(4), 1)
        self.assertEqual(count_bits(7), 3)
        self.assertEqual(count_bits(9), 2)
        self.assertEqual(count_bits(10), 2)