# Create Phone Number

## 문제 설명

* 숫자 리스트가 주어질 때, 주어진 전화번호 포맷대로 리턴한다.

## 나의 풀이 방법

```python
import unittest


def create_phone_number(number_list):
    number = ''.join(map(str, number_list))
    return "({}) {}-{}".format(number[:3], number[3:6], number[6:])
    
    
class TestCreatePhoneNumber(unittest.TestCase):
    def test_create_phone_number(self):
        number_list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
        actual = create_phone_number(number_list)
        self.assertEqual(actual, "(123) 456-7890")

```

* join을 사용해서, 숫자 리스트의 값들을 문자열로 만들어 준 후,
* 전화번호 포맷에 맞게 포맷팅 해주었다.

## 다른 사람의 풀이 방법

* ### Clever

  ```python
  def create_phone_number(n):
      return "({}{}{}) {}{}{}-{}{}{}{}".format(*n)
  ```
  
  *   발상이 좋고, 파이썬의 `*` 활용법을 제대로 보여 준 것 같다.
  *   좋은 코드라기 보다는 `*` 의 활용에 초점을 두고 보면 좋을 것 같다.

## 배운 점

*   `*` 활용에대해서 좀 더 깊게 알 수 있었다.

## 반성할 점

*   문제자체가 어렵지 않아서 반성할 점은 없었다.

## Action Item

*   간단하게 표현 될 수 있는 코드에 대해서는 `*` , `**` 을 적극 활용하자.

