import unittest


def splitstring(s):
    if len(s) % 2:
        s += '_'
    return [s[i : i + 2] for i in range(0, len(s), 2)]


class TestSplitString(unittest.TestCase):
    def test_split_string_with_even_length_string(self):
        self.assertEqual(splitstring("asdfadsf"), ['as', 'df', 'ad', 'sf'])
    def test_split_string_with_odd_length_string(self):
        self.assertEqual(splitstring("asdfads"), ['as', 'df', 'ad', 's_'])    


if __name__ == '__main__':
    unittest.main()