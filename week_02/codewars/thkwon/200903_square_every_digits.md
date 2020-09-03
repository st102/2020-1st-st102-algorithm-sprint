# Square Every Digit

## 문제 설명

* 어떤 숫자가 주어졌을 때, 각 자리 수의 제곱을 한 이후에 그 수를 일렬로 붙인다

## 나의 풀이 방법

```python
import unittest


def square_digits(number):
    sqaure_number_list = [int(element) ** 2 for element in str(number)]
    return int(''.join(map(str, sqaure_number_list)))
    
    
class TestSquareDigits(unittest.TestCase):
    def test_square_digits(self):
        num = 9119
        actual = square_digits(num)
        self.assertEqual(actual, 811181)

```

* square_number_list 를 생성해준 이후에, 이것을 문자열로 바꿔서 일렬로 붙이고, int 로 바꿔주었다.

* 최초 풀이 할 때는 한 줄로 적었었는데, 가독성 측면에서 분리하는 방법을 택하였다.

    

## 다른 사람의 풀이 방법

* ### Best Practice

  ```python
  def square_digits(num):
      ret = ""
      for x in str(num):
          ret += str(int(x)**2)
      return int(ret)
  ```

  * 다른 사람의 답안을 살펴보았을 때, 딱히 베스트 하다고 느낀 코드는 없었던 것 같다
  * 실제로 사람들이 택한 베스트 코드는 위 코드인데,
  * 위 코드가 베스트가 된것에 대해서는 좀 의문이 있다
  * join을 일부러 쓰지 않으려고 한 것 같은 느낌이 드는데, 위 코드는 내가 작성한 방법대로 푸는 것이 더 좋은 선택이라고 느껴진다


## 배운 점

*   이 문제도 딱히 배운 점은 없었다

## 반성할 점

*   이 문제도 딱히 반성할 점은 없었다

## Action Item

*   없음

