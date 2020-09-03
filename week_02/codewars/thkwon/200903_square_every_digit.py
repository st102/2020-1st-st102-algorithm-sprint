import unittest


def square_digits(number):
    sqaure_number_list = [int(element) ** 2 for element in str(number)]
    return int(''.join(map(str, sqaure_number_list)))
    
    
class TestSquareDigits(unittest.TestCase):
    def test_square_digits(self):
        num = 9119
        actual = square_digits(num)
        self.assertEqual(actual, 811181)
