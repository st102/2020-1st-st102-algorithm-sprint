import unittest


def get_middle(s):

    def get_mid_index():
        return len(s) // 2

    if len(s) % 2:
        return s[get_mid_index()]

    return s[get_mid_index() - 1:get_mid_index() + 1]


class TestGetMiddle(unittest.TestCase):
    def test_get_middle_given_s_is_odd(self):
        self.assertEqual(get_middle("testing"), "t")

    def test_get_middle_given_s_is_even(self):
        self.assertEqual(get_middle("middle"), "dd")
