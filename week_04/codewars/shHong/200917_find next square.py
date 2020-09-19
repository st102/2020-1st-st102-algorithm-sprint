import unittest


def find_next_square(sq):
    ret = sq ** 0.5
    return int((ret + 1) ** 2) if ret.is_integer() else -1


class TestFindNextSquare(unittest.TestCase):
    def test_find_next_square_return_next_square(self):
        self.assertEqual(find_next_square(12 * 12), 13 * 13)
    def test_find_next_square_return_false_value(self):
        self.assertEqual(find_next_square(123), -1)


if __name__ == '__main__':
    unittest.main()