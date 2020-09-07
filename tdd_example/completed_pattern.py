import unittest


def pattern(number):
    return '\n'.join(''.join(str(char) for char in range(number, index, -1)) for index in range(number))


class TestPattern(unittest.TestCase):
    def test_should_return_empty_string_when_given_n_is_less_than_1(self):
        self.assertEqual(pattern(0), '')

    def test_pattern_given_n_is_equal_more_than_1(self):
        self.assertEqual(pattern(5), "54321\n5432\n543\n54\n5")
