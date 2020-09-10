import unittest


def count_bits(number):
    return sum(int(n) for n in bin(number)[2:])


class TestSpinWords(unittest.TestCase):
    def test_count_bits(self):
        self.assertEqual(count_bits(3), 2)
        self.assertEqual(count_bits(4), 1)
        self.assertEqual(count_bits(1234), 5)


if __name__ == "__main__":
    unittest.main()