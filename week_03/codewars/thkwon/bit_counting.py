import unittest

ONE = '1'


def count_bits(number):
    return bin(number).count(ONE)
    
    
class TestCountBits(unittest.TestCase):
    def test_count_bits_should_return_0_when_given_n_is_0(self):
        self.assertEqual(count_bits(0), 0)

    def test_count_bits_with_common_case(self):
        self.assertEqual(count_bits(7), 3)
