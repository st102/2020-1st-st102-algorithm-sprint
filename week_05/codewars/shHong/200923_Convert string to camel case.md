# 05주차 Convert string to camel case - python

## 문제 설명
* 입력받은 문자열을 camel case로 바꾼다.

## 풀이방법
```python
import unittest
import re


def to_camel_case(text):
    textlist = re.split('-|_', text)
    return textlist[0] + "".join(txt.title() for txt in textlist[1:])


class TestToCamelCase(unittest.TestCase):
    def test_to_camel_case_with_hyphen_string(self):
        self.assertEqual(to_camel_case("hello-world-hello"), "helloWorldHello")

    def test_to_camel_case_with_underbar_string(self):
        self.assertEqual(to_camel_case("hello_world_hello"), "helloWorldHello")

    def test_to_camel_case_with_mixed_case_string(self):
        self.assertEqual(to_camel_case("hello_world-hello"), "helloWorldHello")


if __name__ == '__main__':
    unittest.main()
```
* ```re.split()```을 사용하여 -_ 두가지 경우에 split()시켰다.

## 다른사람의 풀이방법

### Best practice
```python
def to_camel_case(s):
    return s[0] + s.title().translate(None, "-_")[1:] if s else s
```
* ```title()```은 한단어만 title화 시키는 줄 알았는데 모든 단어를 title로 만든다는 것을 알았다.

### Clever
```python
def to_camel_case(text):
    return text[0] + ''.join([w[0].upper() + w[1:] for w in text.replace("_", "-").split("-")])[1:] if text else ''
```
* 언더바를 하이픈으로 변경 후 split했다.

## 배운점
* title의 정확한 사용법. translate.

## 반성할점
* .

## Action Item
* 효율적인 프로그램 작성.