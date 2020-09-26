# 05주차 Are they the same - python

## 문제 설명
* array1 원소의 제곱이 array2라면 true

## 풀이방법
```python
import unittest


def comp(array1, array2):
    if array1 == [] or array2 == []:
        return True if array1 == array2 else False
    
    for n1, n2 in zip(sorted(array1, key = abs), sorted(array2, key = abs)):
        if n1 ** 2 != n2:
            return False
    return True
    
        

class TestComp(unittest.TestCase):
    def test_comp_should_return_True(self):
        self.assertEqual(comp([1,2,3,4], [1,4,9,16]), True)
    def test_comp_with_empty_array_should_return_False(self):
        self.assertEqual(comp([], [1]), False)
    def test_comp_with_negative_should_return_True(self):
        self.assertEqual(comp([-1,-2,-3,-4], [1,4,9,16]), True)


if __name__ == '__main__':
    unittest.main()
```
* 절대값으로 정렬 후 하나씩 비교. 
* list가 비었을 때, 원소가 음수일 때의 경우를 testcode에 추가했다.

## 다른사람의 풀이방법

### Best practice
```python
def comp(array1, array2):
    try:
        return sorted([i ** 2 for i in array1]) == sorted(array2)
    except:
        return False
```
* try-except 문을 이용하여 sorted되지 않는 경우를 false를 return하도록 했다.
* list도 ==연산자를 통해 비교가 되는 것을 알았다.

### Clever
```python
def comp(a1, a2):
    return None not in (a1,a2) and [i*i for i in sorted(a1)]==sorted(a2)
```
* 간결하지만 음수인 경우에 대해 반례가 존재한다.

## 배운점
* list 비교

## 반성할점
* .

## Action Item
* 효율적인 프로그램 작성.