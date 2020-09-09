import unittest


def filter_list(l):
    return [item for item in l if isinstance(item, int)]


class TestFilterList(unittest.TestCase):
    def test_filter_list_with_str_list(self):
        self.assertEqual(filter_list(["hello", "world"]), [])
    def test_filter_list_with_int_list(self):
        self.assertEqual(filter_list([1, 2, 3, 4]), [1, 2, 3, 4])
    def test_filter_list_with_mixed_list(self):
        self.assertEqual(filter_list([1, 2, 3, "1", "2"]), [1, 2, 3])


if __name__ == "__main__":
    unittest.main()