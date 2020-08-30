import unittest


def disemvowel(string):
    return ''.join(char for char in string if char not in 'aeiouAEIOU')


class TestDisemvowel(unittest.TestCase):
    def test_disemvowel(self):
        string = "This website is for losers LOL!"
        actual = disemvowel(string)
        self.assertEqual(actual, "Ths wbst s fr lsrs LL!")
