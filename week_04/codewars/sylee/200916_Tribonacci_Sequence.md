# Tribonacci Sequence

## 문제설명

> n번째 항은 n-3, n-2, n-1번째 항의 합이다.  최초 패턴이 주어진다.

## 나의 풀이 방법

 ```python
import unittest


def tribonacci(signature, n):
    list_tribonacci = signature
    if n < 4:
        return signature[:n]
    else:
        for i in range(3, n):
            list_tribonacci.append(sum(list_tribonacci[-3:]))
        return list_tribonacci


class TestTribonacci(unittest.TestCase):
    def test_signature_is_111(self):
        self.assertEqual(tribonacci([1, 1, 1], 10), [1, 1, 1, 3, 5, 9, 17, 31, 57, 105])

    def test_signature_is_000(self):
        self.assertEqual(tribonacci([0, 0, 0], 10), [0, 0, 0, 0, 0, 0, 0, 0, 0, 0])

    def test_when_n_is_1(self):
        self.assertEqual(tribonacci([1, 1, 1], 1), [1])

    def test_when_n_is_0(self):
        self.assertEqual(tribonacci([300, 200, 100], 0), [])

 ```

> 시그니쳐 2 가지에 대해 테스트 하고
>
> n 이 1 일때와 2일때 두가지 경우에 대해 테스트 해보았다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def tribonacci(signature, n):
  res = signature[:n]
  for i in range(n - 3): res.append(sum(res[-3:]))
  return res
```

> n의 크기에 대해 검사할 필요가 없다는 걸 배웠다.
>
> 그 후 n이 3 이상이면 `n-3`번 만큼만 뒤에 추가해주었다.



## 배운 점

>  index를 잘 활용하면 불필요한 검사를 줄일 수 있다.



## 반성할 점

> 리팩토링 과정이 부족했다.



## Action Item

> index활용