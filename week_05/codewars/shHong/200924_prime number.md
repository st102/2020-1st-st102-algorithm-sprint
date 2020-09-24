# 05주차 Is a number prime? - python

## 문제 설명
* 소수판별

## 풀이방법
```python
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
```
* n번, n/2번 실행하는 것은 너무 오래걸려 제곱근까지만 판별하여 실행시간을 단축시켰다.

## 다른사람의 풀이방법

### Best practice
```python
import random

def even_odd(n):
    s, d = 0, n
    while d % 2 == 0:
          s += 1
          d >>= 1
    return s, d

def Miller_Rabin(a, p):
    s, d = even_odd(p-1)
    a = pow(a, d, p)
    if a == 1: return True
    for i in range(s):
        if a == p-1: return True
        a = pow(a, 2, p)
    return False

def is_prime(p):
    if p == 2: return True
    if p <= 1 or p % 2 == 0: return False
    return all(Miller_Rabin(random.randint(2,p-1),p) for _ in range(40))
```
* 밀러-라빈 공식을 이용하여 시간을 단축시켰다.

### Clever
```python
def is_prime(num):
    import math

    # There's only one even prime: 2
    if num < 2    : return False
    if num == 2   : return True
    if num %2 == 0: return False

    
    """
    Property:
        Every number n that is not prime has at least one prime divisor p
        such 1 < p < square_root(n)
    """
    root = int(math.sqrt(num))
    
    # We know there's only one even prime, so with that in mind 
    # we're going to iterate only over the odd numbers plus using the above property
    # the performance will be improved
    for i in xrange(3, root+1, 2):
        if num % i == 0: return False

    return True
```
* 나와 같은 코드지만 documented한 코드여서 이해가 쉽다.
* ```xrange()```를 사용하여 메모리사용량을 줄였다.

## 배운점
* 밀러라빈공식, xrange

## 반성할점
* .

## Action Item
* 효율적인 프로그램 작성.