import unittest


def find_short(s):
    return min(map(len, s.split()))


class TestFindShort(unittest.TestCase):
    def test_find_short(self):
        self.assertEqual(find_short('bitcoin take over the world maybe who knows perhaps'), 3)
