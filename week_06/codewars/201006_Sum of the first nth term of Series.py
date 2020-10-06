import unittest


def series_sum(n):
    return "%.2f" % sum(1 / (1 + 3 * i) for i in range(n))


class TestSeriesSum(unittest.TestCase):
    def test_series_sum_with_integer(self):
        self.assertEqual(series_sum(3), "1.39")
    def test_series_sum_with_zero(self):
        self.assertEqual(series_sum(0), "0.00")


if __name__ == '__main__':
    unittest.main()