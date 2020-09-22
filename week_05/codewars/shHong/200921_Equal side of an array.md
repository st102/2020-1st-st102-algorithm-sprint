# 05주차 Equal side of an Array - python

## 문제 설명
* 입력받은 정수의 list에서 양 사이드의 합이 같아지는 index return, else -1

## 풀이방법
```python
import unittest


def find_even_index(arr):
    for i in range(len(arr)):
        if sum(arr[:i]) == sum(arr[i+1:]):
            return i
    return -1


class TestFindEvenIndex(unittest.TestCase):
    def test_find_even_index_should_return_true_value(self):
        self.assertEqual(find_even_index([1,2,3,4,3,2,1]),3)
        self.assertEqual(find_even_index([20,10,30,10,10,15,35]),3)

    def test_find_even_index_should_return_false_value(self):
        self.assertEqual(find_even_index([1,2,3,4,5,6]),-1)


if __name__ == '__main__':
    unittest.main()
```
* 모든 인덱스를 탐색하는데 양 사이드의 합이 같다면 return했다.

## 다른사람의 풀이방법

### Best practice
```python
def find_even_index(arr):
    for i in range(len(arr)):
        if sum(arr[:i]) == sum(arr[i+1:]):
            return i
    return -1
```
* 내가 best다.

### Clever
```python
def find_even_index(lst):
    left_sum = 0
    right_sum = sum(lst)
    for i, a in enumerate(lst):
        right_sum -= a
        if left_sum == right_sum:
            return i
        left_sum += a
    return -1
```
* 이미 오른쪽의 값을 다 더해놓고 오른쪽으로 인덱스가 이동할 때 마다 이동한 원소를 뺐다.
* 매번 ```sum()```을 실행시키는 것 보다 미리 더해 놓고 빼는 것이 시간복잡도의 관점에서 효율적인 것 같다.

## 배운점
* .

## 반성할점
* 문제 그대로 받아들여 작성했지만 더 효율적으로 생각해보는 연습을 해야겠다.

## Action Item
* 효율적인 프로그램 작성.