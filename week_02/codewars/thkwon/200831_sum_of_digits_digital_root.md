# Sum Of Digits / Digital Root

## 문제 설명

*   Digital Root 에 대한 결과값을 리턴해라.
    *   Digital root는 어떤 숫자의 각 digit를 재귀적으로 합한 것을 말한다.

## 나의 풀이 방법

```python
# 최초 풀이
import unittest


def digital_root(number):
    str_number = str(number)

    if number < 10:
        return number

    while len(str_number) > 1:

        sum_of_num = sum(int(element) for element in str_number)

        if sum_of_num >= 10:
            str_number = str(sum_of_num)
        else:
            return sum_of_num


class TestDigitalRoot(unittest.TestCase):
    def test_digital_root(self):
        self.assertEqual(digital_root(16), 7)

    def test_digital_root_number_is_0(self):
        self.assertEqual(digital_root(0), 0)

    def test_digital_root_number_should_return_given_number_when_number_is_less_than_10(self):
        self.assertEqual(digital_root(1), 1)
        self.assertEqual(digital_root(2), 2)
        self.assertEqual(digital_root(3), 3)
        self.assertEqual(digital_root(4), 4)
        self.assertEqual(digital_root(5), 5)

```

*   주어진 number 를 애초에 string으로 변환 후에 무언가를 해보겠다라는 생각을 가지고 문제를 풀었다
*   이 선택으로 인해서, string에서 int로 바꿨다가 말았다가 하는 불필요한 과정이 들어가게 되고, 불필요한 while 이 생겼다

```python
# 나중에 수정한 방법
import unittest


def digital_root(number):
    sum_of_num = number
    
    while sum_of_num > 10:
        sum_of_num = sum(int(element) for element in str(sum_of_num))
        
    return sum_of_num


class TestDigitalRoot(unittest.TestCase):
    def test_digital_root(self):
        self.assertEqual(digital_root(16), 7)

    def test_digital_root_number_is_0(self):
        self.assertEqual(digital_root(0), 0)

    def test_digital_root_number_should_return_given_number_when_number_is_less_than_10(self):
        self.assertEqual(digital_root(1), 1)
        self.assertEqual(digital_root(2), 2)
        self.assertEqual(digital_root(3), 3)
        self.assertEqual(digital_root(4), 4)
        self.assertEqual(digital_root(5), 5)
```

*   사실 이문제는 위와 같이 간단히 표현이 가능하다
*   number가 1자리수일 때 와 그 이외 일 때를 나누어서 1자리수 일 때는 그대로 return, 1자리 수가 아닐 때는 반복문으로 1의자리가 될 때까지 각 자리의 합을 더하면 되는 문제 였다.

## 다른 사람의 풀이 방법

* ### Best Practice

  ```python
  def digital_root(n):
    if n < 10:
      return n
    return digital_root(sum(map(int, str(n))))
  ```

  * 사실 이 문제의 베스트 프랙티스는 위 문제가 맞다
  * 왜냐하면, 문제 자체에 digital_root 에 재귀적인 합이라는 힌트를 주었기 때문이다
  * 의도 자체가 재귀를 활용해서 풀어보라는 문제였을 것 이라고 예상하였지만, 모든 재귀는 반복문으로 풀 수 있기 때문에 나 같은 경우에는 반복문으로 푸는 방법을 택하였다
  * 하지만, 위 코드에서 볼 수 있다시피 재귀로 푸는게 훨씬 직관적이고 가독성이 좋음을 알 수 있따

* ### Clever

  ```python
  def digital_root(n):
      return n%9 or n and 9 
  ```

  *   binary 값을 기준으로 or , and 연산을 수행하여 계산한다.
  *   이 부분은 추후에 다시 좀 더 풀이를 연구해서 보충 할 예정

## 배운 점

*   재귀와 반복문으로 연습해볼 만한 문제를 하나 더 배울 수 있었다

## 반성할 점

*   문제에 재귀에 대한 언급이 있다면, 왠만하면 재귀로 풀 수 있도록 하고, 반복문으로도 같이 풀어보도록 하자.

## Action Item

*   문제에서 재귀의 느낌이 나면, 재귀로 꼭 풀어보고, 반복문을 사용해서도 꼭 풀어보도록 하자.

