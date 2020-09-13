import unittest


def duplicate_count(text):
    text = text.lower()
    return sum(1 for c in set(text) if text.count(c) > 1)


class TestDuplicateCount(unittest.TestCase):
    def test_duplicate_count_with_no_duplicate(self):
        self.assertEqual(duplicate_count("abcdefg"), 0)
    def test_duplicate_count_with_lower_alpha_duplicate(self):
        self.assertEqual(duplicate_count("aabbccdd"), 4)
    def test_duplicate_count_with_mixed_alpha_duplicate(self):
        self.assertEqual(duplicate_count("aabBCCcdde"), 4)


if __name__ == '__main__':
    unittest.main()