import unittest


def digitize(n):
    return [int(num) for num in str(n)[::-1]]


class TestDigitize(unittest.TestCase):
    def test_digitize(self):
        self.assertEqual(digitize(1234), [4,3,2,1])


if __name__ == '__main__':
    unittest.main()
    