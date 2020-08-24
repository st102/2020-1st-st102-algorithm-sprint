import unittest


def get_count(input_str):
    return sum(1 for char in input_str if char in 'aeiou')


class TestGetCount(unittest.TestCase):
    def test_get_count_should_return_0_with_empty_string(self):
        input_str = ''
        actual = get_count(input_str)
        self.assertEqual(actual, 0)

    def test_get_count_should_return_0_with_no_vowel(self):
        input_str = 'qwrtp'
        actual = get_count(input_str)
        self.assertEqual(actual, 0)

    def test_get_count_should_return_5_with_only_vowel(self):
        input_str = 'aeiou'
        actual = get_count(input_str)
        self.assertEqual(actual, 5)
