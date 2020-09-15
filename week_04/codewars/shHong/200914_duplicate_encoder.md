# 04주차 Duplicate Encoder - python

## 문제 설명
* 입력받은 문자열에서 중복된 단어는 )로, 그렇지 않으면 (로 치환하여 반환한다.

## 풀이방법
```python
import unittest


def duplicate_encode(word):
    word = word.lower()
    return "".join(")" if word.count(c) > 1 else "(" for c in word)


class TestDuplicateEncode(unittest.TestCase):
    def test_duplicate_encode_with_single_words(self):
        self.assertAlmostEqual(duplicate_encode("abcde"), "(((((")
    def test_duplicate_encode_with_duplicated_words(self):
        self.assertAlmostEqual(duplicate_encode("aabbccddee"), "))))))))))")
    def test_duplicate_encode_with_mixed_words(self):
        self.assertAlmostEqual(duplicate_encode("aABbCcddef"), "))))))))((")


if __name__ == '__main__':
    unittest.main()
```
* 대소문자를 구분하지 않기때문에 먼저 소문자화 시킨 후 변환했다.

## 다른사람의 풀이방법

### Best practice
```python
def duplicate_encode(word):
    return "".join(["(" if word.lower().count(c) == 1 else ")" for c in word.lower()])
```
* 나와 같은 코드. 저번 문제와 같다.
* clever 또한 저번과 비슷해서 정하지 않기로 했다.

## 배운점
* .

## 반성할점
* .

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.