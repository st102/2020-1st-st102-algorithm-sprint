# Bit Counting

## ��������

> ������ �ϳ� �޾� �������� ��ȯ���� ��, 1�� ������ ��ȯ

 ```python
import unittest


def count_bits(n):
    return sum(int(x) for x in bin(n)[2:])


class TestCountBits(unittest.TestCase):
    def test_bit(self):
        self.assertEqual(count_bits(0), 0)
        self.assertEqual(count_bits(4), 1)
        self.assertEqual(count_bits(7), 3)
        self.assertEqual(count_bits(9), 2)
        self.assertEqual(count_bits(10), 2)
 ```

> codewars�� �ִ� �׽�Ʈ �ڵ带 ����ߴµ�,  0�� ���� 0�� �ƴҶ� �ΰ��� ���̽� ������
>
> �˻��ص� �� �� ����.




## �ٸ� ����� Ǯ�� ���

```python
# Best Practices 1
def countBits(n):
    return bin(n).count("1")
```

> ���� �̸��� `Counting`�ε� ���� �� `sum()`�� �̿��ߴ��� �𸣰ڴ�. ����
>
> `count()`�� �̿��ϸ� �� ����������.



```python
# Best Practices 2
def countBits(n):
    return '{:b}'.format(n).count('1')
```

> `{:b}`�� �̿��Ͽ� 2������ ���� �� �ִٴ� ���� �˾Ҵ�.
>
> �߰��� `format(n, 'b').count('1')`�ε� �� �� �ִ�.





## ��� ��

>  format�� �̿��� ���� ��ȯ�� �˰� �Ǿ���.



## �ݼ��� ��

> ���������� ������ ���� ������ ������ �� ����.



## Action Item

> ���� �� �����ϱ�

