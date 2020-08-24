# Fibonacci5

## 문제 설명

*   20이하의 n을 입력 되었을 때, n 번째 피보나치 수를 구하여라.

## 나의 풀이 방법

```python
# with recursion

import unittest

MEMOIZATION = [0] * 20


def fibonacci(num):
    if num == 0:
        return 0
    if num <= 2:
        return 1
    if MEMOIZATION[num] != 0:
        return MEMOIZATION[num]

    MEMOIZATION[num] = fibonacci(num - 1) + fibonacci(num - 2)

    return MEMOIZATION[num]


class TestFibonacci(unittest.TestCase):
    def test_should_return_1_when_given_num_is_1(self):
        self.assertEqual(fibonacci(1), 1)

    def test_should_return_1_when_given_num_is_2(self):
        self.assertEqual(fibonacci(2), 1)

    def test_should_return_2_when_given_num_is_3(self):
        self.assertEqual(fibonacci(3), 2)

    def test_should_return_3_when_given_num_is_4(self):
        self.assertEqual(fibonacci(4), 3)

    def test_should_return_55_when_given_num_is_10(self):
        self.assertEqual(fibonacci(10), 55)

    def test_should_return_0_when_given_num_is_0(self):
        self.assertEqual(fibonacci(0), 0)

```



```python
import unittest

FIBONACCI_LIST = [0] * 20


def fibonacci(num):
    FIBONACCI_LIST[0] = 0
    FIBONACCI_LIST[1] = 1

    for i in range(2, num + 1):
        FIBONACCI_LIST[i] = FIBONACCI_LIST[i - 1] + FIBONACCI_LIST[i - 2]
    return FIBONACCI_LIST[num]


class TestFibonacciWithDP(unittest.TestCase):
    def test_should_return_1_when_given_num_is_1(self):
        self.assertEqual(fibonacci(1), 1)

    def test_should_return_1_when_given_num_is_2(self):
        self.assertEqual(fibonacci(2), 1)

    def test_should_return_2_when_given_num_is_3(self):
        self.assertEqual(fibonacci(3), 2)

    def test_should_return_3_when_given_num_is_4(self):
        self.assertEqual(fibonacci(4), 3)

    def test_should_return_55_when_given_num_is_10(self):
        self.assertEqual(fibonacci(10), 55)

    def test_should_return_0_when_given_num_is_0(self):
        self.assertEqual(fibonacci(0), 0)

```

* 기본적인 피보나치 문제이다.
* 피보나치 수열은 재귀로도 풀 수 있고, 재귀 + 메모이제이션, DP 를 이용해서도 풀 수 있다
* 사실 모든 for문은 재귀로 바꿀 수 있고, 모든 재귀는 for문으로 다시 바꿔서 풀 수 있다
* 이말인 즉슨, 재귀로 풀 수 있는 문제들은 DP 로도 풀 수있고, DP로 풀 수 있는 문제는 재귀로도 풀 수 있다
* 다만, 재귀를 사용할 때, 단순히 재귀만 사용한다면, 피보나치 수열의 경우에 성능상 큰 문제가 발생한다
* 이를 메워줄 수 있는 것이 메모이제이션 기법이다.
* 메모이제이션은 일종의 캐시 이다. 중복된 계산을 또 하지 않고, 바로 반환하여서, 성능을 향상 시켜준다.

## 다른 사람의 풀이 방법

```python
# https://deokkk9.tistory.com/25

def fibonacci(num):
    if num<=1:
        return num
    return fibonacci(num-1)+fibonacci(num-2)
```

* 이 풀이는 전형적인 재귀 풀이 방법이다.
* 이 문제는 통과했을 지 몰라도, 응답시간에 제한을 둔 혹은 주어지는 `num` 의 값의 제한을 `20` 보다 키웠다면, 백퍼 터졌을 코드이다
* 그러나, 이 전형적인 코드들이 막상 면접가서 손코딩 할 때는 기억나지 않을 때가 많다 이런 코드들을 유심있게 보고 이해하고 여러번 반복해서 설명도 해보고, 써보기도 해야한다



> DP 와 관련해서는 마음에 드는 답안을 찾을 수 없었다..



## 배운 점

*   피보나치 수열은 사실 학생 때부터 너무나도 많이 풀어본 문제이나 늘 볼 때마다 새로운 것 같다 이번에도 오랜만에 다시 작성해보면서, 새로운 느낌 이였다

## 반성할 점

* 개발자로써, 문제 해결 능력의 측면에서 `재귀` , `DP` `메모이제이션` 등등은 매우 중요한 키워드 이고, 이전에 공부했던 내용임에도 불구 하고 아직 재귀 / DP 문제 관련한 사고력이 많이 부족한 것 같다.
* 다양한 문제들은 `DP` / `재귀` 의 관점에서 풀어보고 어떤 식으로 `메모이제이션` 을 도입하여 성능향상시킬 것인지 피보나치 수열 이외 많은 문제들을 풀어봐야 한다

## Action Item

*   for문으로 풀 수 있는 문제들은 사실 재귀로도 풀 수 있다 그 문제들을 찾아서 재귀로 풀어보고, 다시 역으로 바꿔도 보자.
    1. factorial
    2. 문자열 프린트
    3. 문자열 역순 프린트
    4. 최대공약수: Euclid Method
    5. 문자열의 길이 계산
    6. 최대 값 찾기
    7. 2진수로 변환하여 출력