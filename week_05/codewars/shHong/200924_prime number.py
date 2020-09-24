import unittest


def is_prime(num):
    if num == 2:
        return True
    if num % 2 == 0 or num < 2:
        return False
    for n in range(2, int(num ** 0.5) + 1):
        if num % n == 0:
            return False
    return True
        

class TestIsPrime(unittest.TestCase):
    def test_is_prime_with_prime_number(self):
        self.assertEqual(is_prime(13), True)
    def test_is_prime_with_not_prime_number(self):
        self.assertEqual(is_prime(4), False)


if __name__ == '__main__':
    unittest.main()
