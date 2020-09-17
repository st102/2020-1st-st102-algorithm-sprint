# 04주차 find next square - python

## 문제 설명
* 입력받은 정수의 제곱근 + 1을 반환한다. 정수가 아닐 시 -1 반환.

## 풀이방법
```python
import unittest


def find_next_square(sq):
    ret = sq ** 0.5
    return int((ret + 1) ** 2) if ret.is_integer() else -1


class TestFindNextSquare(unittest.TestCase):
    def test_find_next_square_return_next_square(self):
        self.assertEqual(find_next_square(12 * 12), 13 * 13)
    def test_find_next_square_return_false_value(self):
        self.assertEqual(find_next_square(123), -1)


if __name__ == '__main__':
    unittest.main()
```
* is_integer를 이용하여 정수인지 판별한다.
* 처음에는 isinstance로 판별하려 했지만 12.0과 같은 수는 float형으로 인식되어 바꿨다.

## 다른사람의 풀이방법

### Best practice
```python
def find_next_square(sq):
    root = sq ** 0.5
    if root.is_integer():
        return (root + 1)**2
    return -1
```
* 같은 방식을 풀어서 작성했다.

## 배운점
* is_integer와 isinstance의 차이.

## 반성할점
* .

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.