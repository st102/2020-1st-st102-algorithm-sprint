import unittest


def create_phone_number(number_list):
    number = ''.join(map(str, number_list))
    return "({}) {}-{}".format(number[:3], number[3:6], number[6:])
    
    
class TestCreatePhoneNumber(unittest.TestCase):
    def test_create_phone_number(self):
        number_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
        actual = create_phone_number(number_list)
        self.assertEqual(actual, "(123) 456-7890")
