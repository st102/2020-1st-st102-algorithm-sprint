import unittest


ALPHABET_COUNT = 26
LOWER_CASE_A_ASCII_ORDER = 97


def alphabet(lower_case_string):
    alphabet_position_list = [-1] * 26

    for char in lower_case_string:
        alphabet_position_list[ord(char) - LOWER_CASE_A_ASCII_ORDER] = lower_case_string.index(char)

    return ' '.join(map(str, alphabet_position_list))
    
    
class TestAlphabet(unittest.TestCase):
    def test_alphabet(self):
        self.assertEqual(
            alphabet('baekjoon'),
            '1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1',
        )
