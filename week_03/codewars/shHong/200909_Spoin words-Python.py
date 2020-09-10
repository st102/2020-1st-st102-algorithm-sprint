import unittest


def spin_words(sentence):
    return " ".join(word[::-1] if len(word) >= 5 else word for word in sentence.split())


class TestSpinWords(unittest.TestCase):
    def test_spin_words_with_words_length_under_4(self):
        self.assertEqual(spin_words("Hong se hwa"), "Hong se hwa")
    def test_spin_words_with_words_length_over_5(self):
        self.assertEqual(spin_words("Hello World icedAmericano drink JwabJwab"),
         "olleH dlroW onaciremAdeci knird bawJbawJ")
    def test_spin_words_with_words_length_mix(self):
        self.assertEqual(spin_words("Hong se hwa JJANG"), "Hong se hwa GNAJJ")

if __name__ == "__main__":
    unittest.main()