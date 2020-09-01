# Who likes

## 문제 설명

* 리스트에 제시된 이름을 포맷에 맞게 출력한다.

## 나의 풀이 방법

```python
# 최초 풀이
import unittest

def likes(names):
    if not names:
        return 'no one likes this'
    if len(names) == 1:
        return '{} likes this'.format(names[0])
    if len(names) == 2:
        return '{} and {} like this'.format(names[0], names[1])
    if len(names) == 3:
        return '{}, {} and {} like this'.format(names[0], names[1], names[2])
    if len(names) >= 4:
        return '{}, {} and {} others like this'.format(names[0], names[1], len(names) - 2)
    
    
class TestWhoLikesIt(unittest.TestCase):
    def test_likes_should_return_ele_like_this_when_ele_length_is_zero(self):
        names = []
        result = likes(names) 
        self.assertEqual(result, 'no one likes this')
        
    def test_likes_should_return_ele_and_ele_like_this_when_ele_length_is_one(self):
        names = ['Peter']
        result = likes(names)
        self.assertEqual(result, 'Peter likes this')
        
    def test_likes_should_return_ele_comma_ele_and_ele_like_this_when_ele_length_is_two(self):
        names = ['Jacob', 'Alex']
        result = likes(names)
        self.assertEqual(result, 'Jacob and Alex like this')
        
    def test_likes_should_return_ele_comma_ele_and_ele_like_this_when_ele_length_is_three(self):
        names = ['Max', 'John', 'Mark']
        result = likes(names)
        self.assertEqual(result, 'Max, John and Mark like this')
        
    def test_likes_should_return_ele_comma_ele_and_ele_and_others_like_this_when_ele_length_is_four(self):
        names = ['Alex', 'Jacob', 'Mark', 'Max']
        result = likes(names)
        self.assertEqual(result, 'Alex, Jacob and 2 others like this')
```

* 위 문제는 작년 11월 쯤 푼 문제로 생각되어진다.

* 지금 봐도 딱히 가독성에 신경쓰지 않은 채로 푼 것으로 보인다.

  

```python
# 나중에 수정한 방법
import unittest

MAX_INDEX = 4
MAX_KWARGS_COUNT = 3

NO_ONE_LIKES = "no one likes this"
ONLY_ONE_LIKES = "{} likes this"
TWO_LIKES = "{} and {} like this"
THREE_LIKES = "{}, {} and {} like this"
OVER_FOUR_LIKES = "{}, {} and {rest} others like this"


def likes(names):
    length_of_names = len(names)

    return {
        0: NO_ONE_LIKES,
        1: ONLY_ONE_LIKES,
        2: TWO_LIKES,
        3: THREE_LIKES,
        4: OVER_FOUR_LIKES,
    }[min(length_of_names, MAX_INDEX)].format(*names[:MAX_KWARGS_COUNT], rest=length_of_names - 2)


class TestLikes(unittest.TestCase):
    def test_likes_no_one(self):
        self.assertEqual(likes([]), "no one likes this")

    def test_likes_only_one(self):
        self.assertEqual(likes(["Peter"]), "Peter likes this")

    def test_likes_two(self):
        self.assertEqual(likes(["Jacob", "Alex"]), "Jacob and Alex like this")

    def test_likes_three(self):
        self.assertEqual(likes(["Max", "John", "Mark"]), "Max, John and Mark like this")

    def test_likes_over_four(self):
        self.assertEqual(likes(["Alex", "Jacob", "Mark", "Max"]), "Alex, Jacob and 2 others like this")

    def test_likes_over_five(self):
        self.assertEqual(likes(["Alex", "Jacob", "Mark", "Max", "Kwon"]), "Alex, Jacob and 3 others like this")
```

*   매직넘버들은 모두 모두 상수처리를 하고, 테스트도 깔끔하고 보기 좋게 바꾸었다.
*   특히나 지저분한 if else 문을 dict를 이용하여서 깔끔하게 바꾸었다.

## 다른 사람의 풀이 방법

* ### Best Practice

  ```python
  def likes(names):
      s, v, o = '', ' like', ' this'
      if len(names) == 0:
          s = 'no one'
          v += 's'
      elif len(names) == 1:
          s = names[0]
          v += 's'
      elif len(names) == 2:
          s = '{} and {}'.format(names[0], names[1])
      elif len(names) == 3:
          s = '{}, {} and {}'.format(names[0], names[1], names[2])
      else:
          s = '{}, {} and {} others'.format(names[0], names[1], len(names) - 2)
          
      return s + v + o
  ```

  * 이 답은 이 문제에서 문장자체를 주어 동사 목적어로 보았다.
  * 발상도 매우 좋고, 주어 동사 목적어로 되어있으니 은근히 가독성에도 나쁘지 않은 것 같다.

  

* ### Clever

  ```python
  def likes(names):
      if not names:
          return 'no one likes this'
    if len(names) == 1:
          return '{} likes this'.format(names[0])
      if len(names) < 4:
          return '{} like this'.format(' and '.join([', '.join(names[:-1]), names[-1]]))
      return '{}, {} and {} others like this'.format(names[0], names[1], len(names) - 2)
  ```
  
  *   최대한 if문을 줄여서 사용한 풀이이다.
  *   if 문 개수를 줄이려는 시도로 join문을 복합적으로 사용하였는데, join을 복합 적으로 사용한 것이 Clever한 문제라는 느낌이 들어서 선택하게 되었다.

## 배운 점

*   파이썬 문자열 포맷팅에 대해서 좀 더 깊게 알 수 있는 계기가 되었다.

## 반성할 점

*   최초 if 문으로 풀었을 때, dict로 바꾸면 더 지저분해질 것이라고 생각하고 시도해  보지 않았는데, if문으로 쓸 수 있는 것들은 대부분 dict로도 표현되기 때문에 둘 다 풀어보고, 더 가독성 좋은 것을 고르도록 하자.

## Action Item

*   Raw string과 매직 넘버는 상수로 지정하다.

