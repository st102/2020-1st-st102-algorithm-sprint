import unittest


def filter_list(l):
    return [element for element in l if type(element) == type(1)]


class TestFilter(unittest.TestCase):
    def test_should_fail_when_given_only_int(self):
        self.assertEqual(filter_list([1, 2, 3]), [1, 2, 3])

    def test_should_fail_when_given_int_with_string(self):
        self.assertEqual(filter_list([1, "2", 3]), [1, 3])