import unittest


def find_outlier(integers):
    div_list = [n % 2 for n in integers]
    for n in set(div_list):
        if div_list.count(n) == 1:
            return integers[div_list.index(n)]


class TestFindOutlier(unittest.TestCase):
    def test_find_outlier_with_one_odd_number(self):
        self.assertEqual(find_outlier([2, 3, 4, 6, 8, 10, -12]), 3)
    def test_find_outlier_with_one_even_number(self):
        self.assertEqual(find_outlier([1, 2, 3, 5, 7, 9, -11]), 2)


if __name__ == "__main__":
    unittest.main()