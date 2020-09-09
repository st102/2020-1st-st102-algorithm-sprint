def spin_words(sentence):
    words = sentence.split()
    return " ".join(
        [
            element if len(element) < 5 else "".join(list(reversed(element)))
            for element in words
        ]
    )


class Test_spin_words(unittest.TestCase):
    def test_length_of_word_is_less_than_five_when_given_only_one_word(self):
        self.assertEqual(spin_words("1234"), "1234")

    def test_length_of_word_is_five_or_above_when_given_only_one_word(self):
        self.assertEqual(spin_words("12345"), "54321")

    def test_length_of_word_is_less_than_five_when_given_more_than_one_word(self):
        self.assertEqual(spin_words("123 456 7890"), "123 456 7890")

    def test_length_of_word_is_five_or_above_when_given_more_than_one_word(self):
        self.assertEqual(spin_words("123 456 78910"), "123 456 01987")