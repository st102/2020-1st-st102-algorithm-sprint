# Even or Odd

## 문제 설명

*   주어진 수가 짝수 인지 홀 수 인지 판단해서 알맞은 string을 리턴한다

## 나의 풀이 방법

```python
import unittest

EVEN = "Even"
ODD = "Odd"


def even_or_odd(number):
    return EVEN if number % 2 == 0 else ODD
    
    
class TestEvenOrOdd(unittest.TestCase):
    def test_should_return_even_when_number_is_2(self):
        self.assertEqual(even_or_odd(2), EVEN)

    def test_should_return_even_when_number_is_0(self):
        self.assertEqual(even_or_odd(0), EVEN)

    def test_should_return_odd_when_number_is_3(self):
        self.assertEqual(even_or_odd(3), ODD)

    def test_should_return_odd_when_number_is_negative_1(self):
        self.assertEqual(even_or_odd(-1), ODD)

```

*   이 문제는 매우 간단하다, 나머지를 이용해서 짝수와 홀수를 판단해서 return 하면 된다.
*   여기서 중요포인트라고 한다면, 문자열을 상수로 extract 한 것이다
*   사실 이 문제 함수만 봤을 때는 상수 쓰는 것이 낭비 일 수 있지만, 테스트 코드 까지 고려하였을 때는, 적절한 선택이다
*   만약에 상수로 extract 하지 않았다면 매번 string을 생성해야 하는데, 상수를 쓰면 파일 로드 될 때, 상수 정의 후 재사용할 수 있어서 훨씬 이득이된다

## 다른 사람의 풀이 방법

### Best Practice

```python
def even_or_odd(number):
    return 'Odd' if number % 2 else 'Even'
```

*   if 문은 조건문의 True 여부를 판단하기 때문에 위 처럼 `if number % 2` 만 쓰는게 더 깔끔하다

###Clever

```python
def even_or_odd(number):
  return ["Even", "Odd"][number % 2]
```

*   이 방법은 전혀 생각지 못한 방법이다 나머지 값을 index로 하여서 해당하는 리스트의 element를 리턴해준다
*   nitpick, Clever 하긴 하지만, 사실은 위 Best practice 보다 리스트 생성하는 비용이 더 있을 것 같다(미미하긴 하지만)

## 배운 점

*   `if number % 2` 일 때, Odd를 체크하는게 조금 더 깔끔해 보인다

## 반성할 점

*   이 문제를 통해서는 딱히 반성할 점은 없었다

## Action Item

*   `if` 를 쓸 때, `True` 조건을 판단한다는 점을 적극 활용하자