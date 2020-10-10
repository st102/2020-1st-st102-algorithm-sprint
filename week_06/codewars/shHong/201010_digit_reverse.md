# 06주차 digits reverse - python

## 문제 설명
* 정수를 뒤집어 list로 반환

## 풀이방법
```python
import unittest


def digitize(n):
    return [int(num) for num in str(n)[::-1]]


class TestDigitize(unittest.TestCase):
    def test_digitize(self):
        self.assertEqual(digitize(1234), [4,3,2,1])


if __name__ == '__main__':
    unittest.main()
```

## 다른사람의 풀이방법

### Best practice
```python
def digitize(n):
    return map(int, str(n)[::-1])
```
* python3에서는 map객체 자체를 return 할 수 없고 list로 변환시켜야 한다.

## 배운점
* map도 써보자.

## 반성할점
* .

## Action Item
* 효율적인 프로그램 작성.