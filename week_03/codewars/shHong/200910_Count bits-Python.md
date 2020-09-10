# 02주차 Count bits - python

## 문제 설명
* 입력받은 정수를 2진수로 변환 후 1의 개수 반환.

## 풀이방법
```python
import unittest


def count_bits(number):
    return sum(int(n) for n in bin(number)[2:])


class TestSpinWords(unittest.TestCase):
    def test_count_bits(self):
        self.assertEqual(count_bits(3), 2)
        self.assertEqual(count_bits(4), 1)
        self.assertEqual(count_bits(1234), 5)


if __name__ == "__main__":
    unittest.main()
```
* bin()함수를 이용하면 ```"0b0010"``` 과 같이 표현된다. 2번째 index부터 slice하여 모든 정수의 합을 반환했다.
* Given: 0 이상의 정수를 입력받는다.
* When: 2진수로 변환 후 문자열 slicing 하고 모든 수를 더한다.
* then: 1의 총 개수가 반환된다.

## 다른사람의 풀이방법

### Best practice
```python
def countBits(n):
    return bin(n).count("1")
```
* count를 이용해 문자열에서 1의 개수를 반환했다.
* 훨씬 간결하고 문제와 직관적으로 연관된다.

### Clever
```python
def countBits(n):
    return '{:b}'.format(n).count('1')
```
* ```{:b}```를 이용하면 2진수로 바꿀 수 있다는 것을 알았다.
* clever하진 않다. 

## 배운점
* .

## 반성할점
* 과사무실에 지갑 두고온 것을 반성한다 ㅠㅠ

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.