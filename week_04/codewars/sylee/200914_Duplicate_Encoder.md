# Duplicate Encoder

## 문제설명

> 주어진 문자열에서 2회 이상나온 단어는 `)`로 1회만 나온 단어는 `(`로 표현해 출력하라.



## 나의 풀이 방법

 ```python
import unittest
from collections import Counter


def duplicate_encode(word):
    counter = Counter(word.lower())
    return "".join(")" if counter[elem] > 1 else "(" for elem in word.lower())


class MyTestCase(unittest.TestCase):
    def test_when_all_char_appear_only_once(self):
        self.assertEqual(duplicate_encode("din"), "(((")

    def test_when_one_char_appears_more_than_once(self):
        self.assertEqual(duplicate_encode("recede"), "()()()")

    def test_when_several_char_appear_several_times(self):
        self.assertEqual(duplicate_encode("Success"), ")())())")
 ```

> 1. 첫 번째는 모든 단어가 1회만 나올때
> 2.  두 번째는 한 단어만 여러번 나올때
> 3.  세 번째는 여러 단어가 여러번 나올때
>
> 이렇게 3가지 케이스를 나누어 검사했다. 저번 문제에 나온 Counter를 사용해 보았다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def duplicate_encode(word):
    return "".join(["(" if word.lower().count(c) == 1 else ")" for c in word.lower()])
```

> `Counter`를 사용하지 않았으면 나도 이렇게 풀었을 것 같다.
>
> 단, 리스트 `[ ]`는 불필요하다.



```python
# Best Practices 2
from collections import Counter

def duplicate_encode(word):
    word = word.lower()
    counter = Counter(word)
    return ''.join(('(' if counter[c] == 1 else ')') for c in word)
```

> 내 풀이와 거의 비슷하다.
>
> 나도 `word = word.lower()`를 추가하는게 좋았을 것 같다.



## 배운 점

>  특별히 없었다.



## 반성할 점

> 테스트도 케이스를 잘 나누어 짠 것 같다.



## Action Item

> TDD방식으로 계속 해보기 