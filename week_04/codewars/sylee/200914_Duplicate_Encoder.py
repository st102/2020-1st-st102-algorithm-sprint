import unittest
from collections import Counter


def duplicate_encode(word):
    counter = Counter(word.lower())
    return "".join(")" if counter[elem] > 1 else "(" for elem in word.lower())


class MyTestCase(unittest.TestCase):
    def test_when_all_char_appear_only_once(self):
        self.assertEqual(duplicate_encode("din"), "(((")

    def test_when_one_char_appears_more_than_once(self):
        self.assertEqual(duplicate_encode("recede"), "()()()")

    def test_when_several_char_appear_several_times(self):
        self.assertEqual(duplicate_encode("Success"), ")())())")