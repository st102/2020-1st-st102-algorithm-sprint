import unittest


# def filter_list(given_list):
#     return [element for element in given_list if isinstance(element, int)]

def filter_list(given_list):
    return list(filter(lambda element: isinstance(element, int), given_list))


class TestFilterList(unittest.TestCase):
    def test_filter_list(self):
        self.assertEqual(filter_list([1, 2, 'a', 'b']), [1, 2])
