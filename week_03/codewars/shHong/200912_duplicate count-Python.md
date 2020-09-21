# 03주차 duplicate count - python

## 문제 설명
* 입력받은 문자열에서 중복된 단어의 개수를 반환한다.

## 풀이방법
```python
import unittest


def duplicate_count(text):
    text = text.lower()
    return sum(1 for c in set(text) if text.count(c) > 1)


class TestDuplicateCount(unittest.TestCase):
    def test_duplicate_count_with_no_duplicate(self):
        self.assertEqual(duplicate_count("abcdefg"), 0)
    def test_duplicate_count_with_lower_alpha_duplicate(self):
        self.assertEqual(duplicate_count("aabbccdd"), 4)
    def test_duplicate_count_with_mixed_alpha_duplicate(self):
        self.assertEqual(duplicate_count("aabBCCcdde"), 4)


if __name__ == '__main__':
    unittest.main()
```

* 대소문자 구분이 없기에 모두 소문자로 바꾼 후 set으로 부터 단어를 가져와 개수를 셌다.
* 테스트코드는 중복이 없을 때, 소문자만 있는 문자열, 대소문자 섞인 문자열일 때를 검사했다.

## 다른사람의 풀이방법

### Best practice
```python
def duplicate_count(s):
  return len([c for c in set(s.lower()) if s.lower().count(c)>1])
```
* 나와 접근이 같지만 ```s.lower()```가 반복 사용되므로 따로 변수에 저장하는 것이 나을 것 같다.

### Clever
```python
from collections import Counter

def duplicate_count(text):
    return sum(1 for c, n in Counter(text.lower()).iteritems() if n > 1)
```
* clever한 것 같진 않지만 collections 모듈을 알게 되었다.

## 배운점
* collections모듈 외엔 없는 것 같다.

## 반성할점
* 안밀리게 부지런하게 하자.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.