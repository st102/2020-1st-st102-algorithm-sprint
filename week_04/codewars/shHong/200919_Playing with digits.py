import unittest


def dig_pow(n, p):
    add_pow_total = 0
    for i in str(n):
        add_pow_total += int(i) ** p
        p += 1
    return add_pow_total / n if (add_pow_total / n).is_integer() else -1


class TestDigPow(unittest.TestCase):
    def test_dig_pow_should_return_positive_integer(self):
        self.assertEqual(dig_pow(46288, 3), 51)
        self.assertEqual(dig_pow(89, 1), 1)
    def test_dig_pow_should_return_false_value(self):
        self.assertEqual(dig_pow(92, 1), -1)


if __name__ == '__main__':
    unittest.main()