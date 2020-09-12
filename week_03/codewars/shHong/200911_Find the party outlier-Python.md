# 02주차 Find thr party outlier - python

## 문제 설명
* 입력받은 list에서 홀로 홀수이거나 짝수인 수를 return한다.

## 풀이방법
```python
import unittest


def find_outlier(integers):
    div_list = [n % 2 for n in integers]
    for n in set(div_list):
        if div_list.count(n) == 1:
            return integers[div_list.index(n)]


class TestFindOutlier(unittest.TestCase):
    def test_find_outlier_with_one_odd_number(self):
        self.assertEqual(find_outlier([2, 3, 4, 6, 8, 10, -12]), 3)
    def test_find_outlier_with_one_even_number(self):
        self.assertEqual(find_outlier([1, 2, 3, 5, 7, 9, -11]), 2)


if __name__ == "__main__":
    unittest.main()
```
* 입력받은 list의 원소를 2로 나누어 나머지를 저장한다.
* set을 이용하여 탐색횟수를 줄였다.


## 다른사람의 풀이방법

### Best practice
```python
def find_outlier(int):
    odds = [x for x in int if x%2!=0]
    evens= [x for x in int if x%2==0]
    return odds[0] if len(odds)<len(evens) else evens[0]
```
* 홀수, 짝수 list를 따로 만들어 값을 저장했다.
* 같은 list를 2번 반복하여 값을 저장하니 비효율적이라 생각한다.

### Clever
```python
def find_outlier(integers):
    parity = [n % 2 for n in integers]
    return integers[parity.index(1)] if sum(parity) == 1 else integers[parity.index(0)]
```
* 이 코드가 best에 가깝다 생각한다. 모든 값의 합이 1일 경우는 나머지가 1인 경우가 1개만 있을 때 이므로 홀수가 1개일 때 이다.

## 배운점
* ```return integers[div_list.index(n)] for n in set(div_list) if div_list.count(n) == 1```라고 처음에 작성했는데 자꾸 안돼서 뭔가 했는데 iterator comprehension은 하나의 값을 return할 때 쓸 수 없다는 것을 알았다...

## 반성할점
* 이번엔 반성할 점이 없다 생각한다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.