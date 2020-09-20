# 04주차 Playing with digits - python

## 문제 설명
* 각 자리수를 1씩 늘려가며 제곱해서 더했을 때 원래의 값의 자연수배일 경우 배수를 return, 아닌 경우 -1 return

## 풀이방법
```python
import unittest


def dig_pow(n, p):
    add_pow_total = 0
    for i in str(n):
        add_pow_total += int(i) ** p
        p += 1
    return add_pow_total / n if (add_pow_total / n).is_integer() else -1


class TestDigPow(unittest.TestCase):
    def test_dig_pow_should_return_positive_integer(self):
        self.assertEqual(dig_pow(46288, 3), 51)
        self.assertEqual(dig_pow(89, 1), 1)
    def test_dig_pow_should_return_false_value(self):
        self.assertEqual(dig_pow(92, 1), -1)


if __name__ == '__main__':
    unittest.main()
```
* 참이 되는 값을 찾는 것 때문에 테스트코드 작성이 어려웠다.


## 다른사람의 풀이방법

### Best practice
```python
def dig_pow(n, p):
    s = 0
    for i,c in enumerate(str(n)):
        s += pow(int(c),p+i)
    return s/n if s%n==0 else -1
```
* ```enumerate()```를 이용하여 원소와 인덱스 값을 한번에 접근해서 간결해졌다.

### Clever
```python
def dig_pow(n, p):
    k, fail = divmod(sum(int(d)**(p + i) for i, d in enumerate(str(n))), n)
    return -1 if fail else k
```
*  ```divmod()```함수는 몫과 나머지를 반환한다. 유용한 함수를 알게되었다.

## 배운점
* ```divmod()```함수.

## 반성할점
* .

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.