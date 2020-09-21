import unittest


def duplicate_encode(word):
    word = word.lower()
    return "".join(")" if word.count(c) > 1 else "(" for c in word)


class TestDuplicateEncode(unittest.TestCase):
    def test_duplicate_encode_with_single_words(self):
        self.assertAlmostEqual(duplicate_encode("abcde"), "(((((")
    def test_duplicate_encode_with_duplicated_words(self):
        self.assertAlmostEqual(duplicate_encode("aabbccddee"), "))))))))))")
    def test_duplicate_encode_with_mixed_words(self):
        self.assertAlmostEqual(duplicate_encode("aABbCcddef"), "))))))))((")


if __name__ == '__main__':
    unittest.main()