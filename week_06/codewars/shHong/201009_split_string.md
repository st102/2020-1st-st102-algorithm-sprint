# 06주차 Split String - python

## 문제 설명
* 문자열을 2개씩 분리해서 반환

## 풀이방법
```python
import unittest


def splitstring(s):
    if len(s) % 2:
        s += '_'
    return [s[i : i + 2] for i in range(0, len(s), 2)]


class TestSplitString(unittest.TestCase):
    def test_split_string_with_even_length_string(self):
        self.assertEqual(splitstring("asdfadsf"), ['as', 'df', 'ad', 'sf'])
    def test_split_string_with_odd_length_string(self):
        self.assertEqual(splitstring("asdfads"), ['as', 'df', 'ad', 's_'])    


if __name__ == '__main__':
    unittest.main()
```
* 짝수, 홀수 길이의 문자열에 대해 testcode를 작성했다.

## 다른사람의 풀이방법

### Best practice
```python
import re

def solution(s):
    return re.findall(".{2}", s + "_")
```
* re.findall을 사용했고 정규표현식을 통해 모든문자에서 2개 단위로 잘랐다. 
* 짝수의 경우 마지막에 '_' 문자가 붙어 2개를 충족하지 않아 _문자는 생략된다.

## 배운점
* re module, 정규표현식

## 반성할점
* .

## Action Item
* 효율적인 프로그램 작성.