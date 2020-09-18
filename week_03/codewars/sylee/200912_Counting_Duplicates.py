import unittest


def duplicate_count(text):
    text_lower = text.lower()
    return len([elem for elem in set(text_lower) if (text_lower.count(elem) > 1)])


class TestDuplicate(unittest.TestCase):
    def test_should_return_0_when_no_characters_repeat(self):
        self.assertEqual(duplicate_count("1234"), 0)

    def test_should_return_1_when_one_character_repeat(self):
        self.assertEqual(duplicate_count("indivisibility"), 1)

    def test_should_return_1_when_one_character_repeat_with_capital_letter(self):
        self.assertEqual(duplicate_count("abcAde"), 1)

    def test_should_return_2_when_two_character_repeat(self):
        self.assertEqual(duplicate_count("indivisibilities"), 2)

    def test_should_return_2_when_one_character_repeat_with_capital_letter(self):
        self.assertEqual(duplicate_count("aA11"), 2)

    def test_when_given_only_capital_letters(self):
        self.assertEqual(duplicate_count("ABBA"), 2)
