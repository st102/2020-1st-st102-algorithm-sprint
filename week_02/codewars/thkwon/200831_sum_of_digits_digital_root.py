import unittest


def digital_root(number):
    str_number = str(number)

    if number < 10:
        return number

    while len(str_number) > 1:

        sum_of_num = sum(int(element) for element in str_number)

        if sum_of_num >= 10:
            str_number = str(sum_of_num)
        else:
            return sum_of_num


class TestDigitalRoot(unittest.TestCase):
    def test_digital_root(self):
        self.assertEqual(digital_root(16), 7)

    def test_digital_root_number_is_0(self):
        self.assertEqual(digital_root(0), 0)

    def test_digital_root_number_should_return_given_number_when_number_is_less_than_10(self):
        self.assertEqual(digital_root(1), 1)
        self.assertEqual(digital_root(2), 2)
        self.assertEqual(digital_root(3), 3)
        self.assertEqual(digital_root(4), 4)
        self.assertEqual(digital_root(5), 5)
