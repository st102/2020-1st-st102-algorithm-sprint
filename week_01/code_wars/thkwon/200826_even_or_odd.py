import unittest

EVEN = "Even"
ODD = "Odd"


def even_or_odd(number):
    return EVEN if number % 2 == 0 else ODD
    
    
class TestEvenOrOdd(unittest.TestCase):
    def test_should_return_even_when_number_is_2(self):
        self.assertEqual(even_or_odd(2), EVEN)

    def test_should_return_even_when_number_is_0(self):
        self.assertEqual(even_or_odd(0), EVEN)

    def test_should_return_odd_when_number_is_3(self):
        self.assertEqual(even_or_odd(3), ODD)

    def test_should_return_odd_when_number_is_negative_1(self):
        self.assertEqual(even_or_odd(-1), ODD)
