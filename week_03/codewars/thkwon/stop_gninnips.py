import unittest

MAX_WORD_LENGTH_FOR_REVERSING = 5


def spin_words(sentence):
    words = sentence.split()
    return " ".join(
        element if len(element) < 5 else "".join(list(reversed(element)))
        for element in words
    )
    
    
class TestSpinWords(unittest.TestCase):
    def test_spin_words_with_given_sentence_has_all_of_word_length_is_equal_less_than_5(self):
        self.assertEqual(spin_words('Hello World'), 'olleH dlroW')

    def test_spin_words_with_given_sentence_has_all_of_word_length_is_greater_than_5(self):
        self.assertEqual(spin_words('abcdefz bcdefgz cdefghiz'), 'zfedcba zgfedcb zihgfedc')

    def test_spin_words_with_given_sentence_has_word_length_is_greater_than_5_or_not(self):

        self.assertEqual(spin_words('olleH bcdefgz dlroW'), 'Hello zgfedcb World')
