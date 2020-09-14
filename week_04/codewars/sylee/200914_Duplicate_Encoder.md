# Duplicate Encoder

## ��������

> �־��� ���ڿ����� 2ȸ �̻󳪿� �ܾ�� `)`�� 1ȸ�� ���� �ܾ�� `(`�� ǥ���� ����϶�.



## ���� Ǯ�� ���

 ```python
import unittest
from collections import Counter


def duplicate_encode(word):
    counter = Counter(word.lower())
    return "".join(")" if counter[elem] > 1 else "(" for elem in word.lower())


class MyTestCase(unittest.TestCase):
    def test_when_all_char_appear_only_once(self):
        self.assertEqual(duplicate_encode("din"), "(((")

    def test_when_one_char_appears_more_than_once(self):
        self.assertEqual(duplicate_encode("recede"), "()()()")

    def test_when_several_char_appear_several_times(self):
        self.assertEqual(duplicate_encode("Success"), ")())())")
 ```

> 1. ù ��°�� ��� �ܾ 1ȸ�� ���ö�
> 2.  �� ��°�� �� �ܾ ������ ���ö�
> 3.  �� ��°�� ���� �ܾ ������ ���ö�
>
> �̷��� 3���� ���̽��� ������ �˻��ߴ�. ���� ������ ���� Counter�� ����� ���Ҵ�.




## �ٸ� ����� Ǯ�� ���

```python
# Best Practices 1
def duplicate_encode(word):
    return "".join(["(" if word.lower().count(c) == 1 else ")" for c in word.lower()])
```

> `Counter`�� ������� �ʾ����� ���� �̷��� Ǯ���� �� ����.
>
> ��, ����Ʈ `[ ]`�� ���ʿ��ϴ�.



```python
# Best Practices 2
from collections import Counter

def duplicate_encode(word):
    word = word.lower()
    counter = Counter(word)
    return ''.join(('(' if counter[c] == 1 else ')') for c in word)
```

> �� Ǯ�̿� ���� ����ϴ�.
>
> ���� `word = word.lower()`�� �߰��ϴ°� ������ �� ����.



## ��� ��

>  Ư���� ������.



## �ݼ��� ��

> �׽�Ʈ�� ���̽��� �� ������ § �� ����.



## Action Item

> TDD������� ��� �غ��� 