# 04주차 Tribonacci Sequence - python

## 문제 설명
* 트리보나치 구현

## 풀이방법
```python
import unittest


def tribonacci(signature, n):
    tribonaccilist = []
    for i in range(n):
        if i == 0 or i == 1 or i == 2:
            tribonaccilist.append(signature[i])
        else:
            tribonaccilist.append(tribonaccilist[i - 1] + tribonaccilist[i - 2] + tribonaccilist[i - 3])
    return tribonaccilist


class TestTribonacci(unittest.TestCase):
    def test_tribonacci(self):
        self.assertEqual(tribonacci([1, 1, 1], 10), [1, 1, 1, 3, 5, 9, 17, 31, 57, 105])


if __name__ == '__main__':
    unittest.main()
```
* 반복문을 이용하여 O(n)의 시간복잡도를 갖는 코드로 작성했다.
* 테스트코드로 좋은 예가 떠오르지 않아 기본적인 것만 테스트하였다.

## 다른사람의 풀이방법

### Best practice
```python
def tribonacci(signature, n):
  res = signature[:n]
  for i in range(n - 3): res.append(sum(res[-3:]))
  return res
```
* Pythonic하게 잘 짠 것 같다. 

## 배운점
* .

## 반성할점
* 학부수업에서 알려준대로 짜는 것은 간단했지만 python하지 못했던 것 같다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.