# Find The Parity Outlier

## ��������

> ��������Ʈ�� �޾� �ٸ� parity�� ���� ������ ���

## ���� Ǯ�� ���

 ```python
def find_outlier(integers):
    even = 0
    odd = 0

    for element in integers:
        if element % 2:
            odd += 1
        else:
            even += 1
    if even > 1:
        return [x for x in integers if x % 2][0]
    else:
        return [x for x in integers if x % 2 == 0][0]
 ```

> ó�� Ǯ���̴�. 



```python
def find_outlier(integers):
    list_even = [elem for elem in integers if elem % 2 == 0]
    list_odd = [elem for elem in integers if elem % 2]

    return list_even[0] if len(list_even) < len(list_odd) else list_odd[0]
```

> �����丵�� �ڵ��̴�.
>
> �� ����Ʈ �� �ϳ��� ���̴� ������ 1�̰� �ٸ� ����Ʈ�� ���̴� 2 �̻��̴�. (�־��� ����Ʈ�� ���̴� �ּ� 3)
>
> �̸� �̿��Ͽ� �ڵ带 ®��.



```python
class TestFindOutlier(unittest.TestCase):
    def test_when_given_only_odd(self):
        self.assertEqual(find_outlier([2, 4, 6, 8, 10, 3]), 3)

    def test_when_given_only_even(self):
        self.assertEqual(find_outlier([160, 3, 1719, 19, 11, 13, 21]), 160)

    def test_when_given_only_odd_negative(self):
        self.assertEqual(find_outlier([2, 4, 6, 8, 10, -3]), -3)

    def test_when_given_only_even_negative(self):
        self.assertEqual(find_outlier([-160, 3, 1719, 19, 11, 13, 21]), -160)
```

> Ȧ���� ¦���� ���� 1���� ����
>
> �� Ȧ���� ¦���� ���� ������ ������ �׽�Ʈ �ߴ�.




## �ٸ� ����� Ǯ�� ���

```python
# Best Practices 1
def find_outlier(int):
    odds = [x for x in int if x%2!=0]
    evens= [x for x in int if x%2==0]
    return odds[0] if len(odds)<len(evens) else evens[0]
```

> ���� ���� ����. odds�� list comprehension���� if������ True, False�� �˻��ϴµ� 
>
> ���� bool������ �˻��ߴ�.



```python
# Best Practices 2
def find_outlier(integers):
    parity = [n % 2 for n in integers]
    return integers[parity.index(1)] if sum(parity) == 1 else integers[parity.index(0)]
```

> `parity`����Ʈ�� 0�� �����ϰų� 1�� �����ϰ� �ȴ�.
>
> `sum(parity) == 1`�̸� 1�� ���� �ϹǷ� `integers[parity.index(1)]`�� ��ȯ�Ͽ���.
>
> ���� �� ����.



## ��� ��

>  ����Ʈ�� ���� ���������ʰ�, �ʿ��� �κи��� �̴� ����� �����غ���.



## �ݼ��� ��

> Ư���� ������.



## Action Item

> �׽�Ʈ�ڵ�,TDD