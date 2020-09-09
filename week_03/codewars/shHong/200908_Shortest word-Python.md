# 02주차 Shortest word - python

## 문제 설명
* 입력받은 배열에서 정수형 원소만 추출한다.

## 풀이방법
```python
import unittest


def find_short(s):
    return min(map(len, s.split()))


class TestFindShort(unittest.TestCase):
    def test_find_short_with_ascending_order(self):
        self.assertEqual(find_short("1 12 123 1234 12345"), 1)
    def test_find_short_with_same_words(self):
        self.assertEqual(find_short("4444 4444 4444 4444 4444 4444"), 4)


if __name__ == "__main__":
    unittest.main()
```
* 테스트작성할 때 어떤 경우를 테스트 할 지 감이 잘 잡히질 않았다.
* 문자열길이가 오름차순일 때와 모든 문자열의 길이가 같을 때를 검사했다.

## 다른사람의 풀이방법

### Best practice
```python
def find_short(s):
    return min(len(x) for x in s.split())
```
* list comprehension으로 작성했다.

### Clever
```python
def find_short(s):
    return len(sorted(s.split(), key=len)[0])
```
* 문자열의 길이를 key로 지정해 오름차순 정렬을 한 후 0번째 인덱스의 길이를 리턴했다.

## 배운점
* .

## 반성할점
* 테스트코드를 애매모호하게 작성한 것 같다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.