# Equal Sides Of An Array

## ��������

> �� �ε����� �������� ���� ���ҵ��� ���� ������ �ε����� ����Ѵ�. ������ -1



## ���� Ǯ�� ���

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

> 1. ���ǿ� �´� �ε����� ���� ��
> 2. ���ǿ� �´� �ε����� ���� ��
> 3. ���ǿ� �´� �ε����� ������ ���� ��, ���� ���� ���� �ε����� ����ؾ� �Ѵ�.
>    - ��� ���Ұ� 0 �� ����Ʈ�� �޾��� ��  ���� ���� �ε����� 0�� ����ϴ��� �׽�Ʈ�Ѵ�.




## �ٸ� ����� Ǯ�� ���

```python
# Best Practices 1
def find_even_index(arr):
    for i in range(len(arr)):
        if sum(arr[:i]) == sum(arr[i+1:]):
            return i
    return -1
```

> ���� list comprehension�� ����߰� �̰� ������� �ʰ� �����ε��ϴ�.



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

> �迭�� ������ �غ��� �ʾƵ� ���� ���� �� �ִ�. 
>
> ���� ����� �� ����.



## ��� ��

>  �ð� ���⵵�� ���̴� ��.



## �ݼ��� ��

> Ư���� ���ٰ� �����Ѵ�.



## Action Item

> TDD������� ��� �غ��� 