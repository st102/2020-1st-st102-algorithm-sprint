import unittest


def find_outlier(integers):
    list_even = [elem for elem in integers if elem % 2 == 0]
    list_odd = [elem for elem in integers if elem % 2]

    return list_even[0] if len(list_even) < len(list_odd) else list_odd[0]


class TestFindOutlier(unittest.TestCase):
    def test_when_given_only_odd(self):
        self.assertEqual(find_outlier([2, 4, 6, 8, 10, 3]), 3)

    def test_when_given_only_even(self):
        self.assertEqual(find_outlier([160, 3, 1719, 19, 11, 13, 21]), 160)

    def test_when_given_only_odd_negative(self):
        self.assertEqual(find_outlier([2, 4, 6, 8, 10, -3]), -3)

    def test_when_given_only_even_negative(self):
        self.assertEqual(find_outlier([-160, 3, 1719, 19, 11, 13, 21]), -160)