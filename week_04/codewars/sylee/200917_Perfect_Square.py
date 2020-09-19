import math


def find_next_square(sq):
    root = math.sqrt(sq)
    return -1 if root % 1 else (root + 1) ** 2


class TestFindNextSquare(unittest.TestCase):
    def test_not_perfect_square(self):
        self.assertEqual(find_next_square(111), -1)

    def test_perfect_sqaure(self):
        self.assertEqual(find_next_square(121), 144)