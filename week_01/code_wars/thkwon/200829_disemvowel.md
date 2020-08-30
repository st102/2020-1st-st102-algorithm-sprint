# disemvowel

## 문제 설명

*   주어진 string에서, 모음을 제거한다.

## 나의 풀이 방법

```python
import unittest


def disemvowel(string):
    return ''.join(char for char in string if char not in 'aeiouAEIOU')


class TestDisemvowel(unittest.TestCase):
    def test_disemvowel(self):
        string = "This website is for losers LOL!"
        actual = disemvowel(string)
        self.assertEqual(actual, "Ths wbst s fr lsrs LL!")

```

*   generator comprehension을 사용하였고, join을 이용하여서 문자열 형태로 리턴해주었다.

## 다른 사람의 풀이 방법

* ### Best Practice

  ```python
  def disemvowel(string):
      return "".join(c for c in string if c.lower() not in "aeiou")
  ```

  * 이 문제의 베스트 프랙티스는 내가 푼 방법이라고 생각한다.
  * 위 답안은 lower()을 써서 범위를 소문자로 한정하였는가 그렇지 않았는가의 차이만 존재한다.
  * generator expression을 사용하고 이를 다양한 빌트인 메소드로 활용하여서 문제 푸는 방식이 매우 파이써닉 하다

* ### Clever

  ```python
  def disemvowel(s):
      return s.translate(None, "aeiouAEIOU")
  ```

  *   이번을 계기로 translate 라는 빌트인 함수에 대해서 알게되었다.
  *   특정 string에서 특정 char를 공통의 어떤 것으로 수정해야할 때, 유용하게 쓰일 수 있을 것 같다

## 배운 점

*   `translate` 에 대해서 알게되었고, 후에 유용히 써먹을 수 있을 것 같다

## 반성할 점

*   이 문제는 반성할 점이 없다

## Action Item

*   `translate` 를 적극적으로 사용해보자.

