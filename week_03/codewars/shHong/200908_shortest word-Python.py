import unittest


def find_short(s):
    return min(map(len, s.split()))


class TestFindShort(unittest.TestCase):
    def test_find_short_with_ascending_order(self):
        self.assertEqual(find_short("1 12 123 1234 12345"), 1)
    def test_find_short_with_same_words(self):
        self.assertEqual(find_short("4444 4444 4444 4444 4444 4444"), 4)


if __name__ == "__main__":
    unittest.main()