from collections import Counter
import unittest


def find_it(seq):
    counter = Counter(seq)
    return [key for key in counter if counter[key] % 2][0]


class TestFindIt(unittest.TestCase):
    def test_find_it_should_return_element_of_seq_when_seq_length_is_one(self):
        self.assertEqual(find_it([10]), 10)

    def test_find_it_common_case(self):
        self.assertEqual(find_it([1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5]), -1)
