# Equal Sides Of An Array

## 문제설명

> 한 인덱스를 기준으로 양쪽 원소들의 합이 같으면 인덱스를 출력한다. 없을시 -1



## 나의 풀이 방법

 ```python
import unittest


def find_even_index(arr):
    find_index = [
        index
        for index in range(len(arr))
        if (sum(arr[:index]) == sum(arr[index + 1 :]))
    ]
    return find_index[0] if find_index else -1


class TestEqualSide(unittest.TestCase):
    def test_index_exist(self):
        self.assertEqual(find_even_index([1, 2, 3, 4, 3, 2, 1]), 3,)

    def test_index_not_exist(self):
        self.assertEqual(find_even_index(list(range(1, 100))), -1)

    def test_all_list_elem_is_0(self):
        self.assertEqual(find_even_index([0, 0, 0, 0, 0]), 0)
 ```

> 1. 조건에 맞는 인덱스가 있을 때
> 2. 조건에 맞는 인덱스가 없을 때
> 3. 조건에 맞는 인덱스가 여러개 있을 때, 그중 가장 작은 인덱스를 출력해야 한다.
>    - 모든 원소가 0 인 리스트를 받았을 때  가장 작은 인덱스로 0을 출력하는지 테스트한다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def find_even_index(arr):
    for i in range(len(arr)):
        if sum(arr[:i]) == sum(arr[i+1:]):
            return i
    return -1
```

> 나는 list comprehension을 사용했고 이건 사용하지 않고 차이인듯하다.



```python
# Best Practices 2
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

> 배열의 끝까지 해보지 않아도 답을 구할 수 있다. 
>
> 좋은 방식인 것 같다.



## 배운 점

>  시간 복잡도를 줄이는 점.



## 반성할 점

> 특별히 없다고 생각한다.



## Action Item

> TDD방식으로 계속 해보기 