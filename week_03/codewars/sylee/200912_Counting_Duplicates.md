# Counting Duplicates

## 문제설명

> 받은 문자열중에서 몇개의 동일한 문자가 쓰였는지 출력하는 함수 만들기
>
>  (단, 대문자와 소문자는 구분하지 않는다.)



## 나의 풀이 방법

 ```python
import unittest


def duplicate_count(text):
    text_lower = text.lower()
    return len([elem for elem in set(text_lower) if (text_lower.count(elem) > 1)])


class TestDuplicate(unittest.TestCase):
    def test_should_return_0_when_no_characters_repeat(self):
        self.assertEqual(duplicate_count("1234"), 0)

    def test_should_return_1_when_one_character_repeat(self):
        self.assertEqual(duplicate_count("indivisibility"), 1)

    def test_should_return_1_when_one_character_repeat_with_capital_letter(self):
        self.assertEqual(duplicate_count("abcAde"), 1)

    def test_should_return_2_when_two_character_repeat(self):
        self.assertEqual(duplicate_count("indivisibilities"), 2)

    def test_should_return_2_when_one_character_repeat_with_capital_letter(self):
        self.assertEqual(duplicate_count("aA11"), 2)

    def test_when_given_only_capital_letters(self):
        self.assertEqual(duplicate_count("ABBA"), 2)

 ```

> 중복되는 문자가 0개, 1개, 2개 테스트코드를 제작했다. (2개일때 성공하면 2개 이상일때도 성공할 것이다.)
>
> 추가로 대문자만 있을 때도 검사해보았다.

> 1. 대소문자 구분이 없으므로 받은 문자열을 모두 소문자나 대문자로 변환하고 시작했다. (여기선 소문자)
>
> 2. `set()`을 사용하여 문자열에 포함된 원소들을 받는다.
>
> 3. `count()`를 이용해 받은 원소들을 문자열에서 세어 2개 이상이면 리스트에 추가한다. 
>
> 4. 그 리스트의 길이를 반환한다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def duplicate_count(s):
  return len([c for c in set(s.lower()) if s.lower().count(c)>1])
```

> 나와  같은 방법으로 풀었다.



```python
# Best Practices 2
from collections import Counter

def duplicate_count(text):
    counter = Counter(text.lower())
    return len([counter.keys() for i in counter.values() if i>1])
```

> `Counter()`를 이용하여 풀었다.
>
> 이 메소드를 사용하게 되면 각 문자에 대하여 몇번 나왔는지를 딕셔너리로 반환해준다.
>
> 전체적인 흐름은 리스트의 길이를 반환하는 것으로 Best Practices 1 과 같다.



## 배운 점

>  `Counter()`메소드에 대해 새로 알게 되었다.



## 반성할 점

> 테스트코드를 0개, 1개, 1개 이상일 때 로 나누는게 더 좋았을 것 같다.



## Action Item

> 테스트코드를 작성할때 조건을 잘 나누어 보자.

