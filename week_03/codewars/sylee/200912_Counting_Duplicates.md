# Counting Duplicates

## ��������

> ���� ���ڿ��߿��� ��� ������ ���ڰ� �������� ����ϴ� �Լ� �����
>
>  (��, �빮�ڿ� �ҹ��ڴ� �������� �ʴ´�.)



## ���� Ǯ�� ���

 ```python
import unittest


def duplicate_count(text):
    text_lower = text.lower()
    return len([elem for elem in set(text_lower) if (text_lower.count(elem) > 1)])


class TestDuplicate(unittest.TestCase):
    def test_should_return_0_when_no_characters_repeat(self):
        self.assertEqual(duplicate_count("1234"), 0)

    def test_should_return_1_when_one_character_repeat(self):
        self.assertEqual(duplicate_count("indivisibility"), 1)

    def test_should_return_1_when_one_character_repeat_with_capital_letter(self):
        self.assertEqual(duplicate_count("abcAde"), 1)

    def test_should_return_2_when_two_character_repeat(self):
        self.assertEqual(duplicate_count("indivisibilities"), 2)

    def test_should_return_2_when_one_character_repeat_with_capital_letter(self):
        self.assertEqual(duplicate_count("aA11"), 2)

    def test_when_given_only_capital_letters(self):
        self.assertEqual(duplicate_count("ABBA"), 2)

 ```

> �ߺ��Ǵ� ���ڰ� 0��, 1��, 2�� �׽�Ʈ�ڵ带 �����ߴ�. (2���϶� �����ϸ� 2�� �̻��϶��� ������ ���̴�.)
>
> �߰��� �빮�ڸ� ���� ���� �˻��غ��Ҵ�.

> 1. ��ҹ��� ������ �����Ƿ� ���� ���ڿ��� ��� �ҹ��ڳ� �빮�ڷ� ��ȯ�ϰ� �����ߴ�. (���⼱ �ҹ���)
>
> 2. `set()`�� ����Ͽ� ���ڿ��� ���Ե� ���ҵ��� �޴´�.
>
> 3. `count()`�� �̿��� ���� ���ҵ��� ���ڿ����� ���� 2�� �̻��̸� ����Ʈ�� �߰��Ѵ�. 
>
> 4. �� ����Ʈ�� ���̸� ��ȯ�Ѵ�.




## �ٸ� ����� Ǯ�� ���

```python
# Best Practices 1
def duplicate_count(s):
  return len([c for c in set(s.lower()) if s.lower().count(c)>1])
```

> ����  ���� ������� Ǯ����.



```python
# Best Practices 2
from collections import Counter

def duplicate_count(text):
    counter = Counter(text.lower())
    return len([counter.keys() for i in counter.values() if i>1])
```

> `Counter()`�� �̿��Ͽ� Ǯ����.
>
> �� �޼ҵ带 ����ϰ� �Ǹ� �� ���ڿ� ���Ͽ� ��� ���Դ����� ��ųʸ��� ��ȯ���ش�.
>
> ��ü���� �帧�� ����Ʈ�� ���̸� ��ȯ�ϴ� ������ Best Practices 1 �� ����.



## ��� ��

>  `Counter()`�޼ҵ忡 ���� ���� �˰� �Ǿ���.



## �ݼ��� ��

> �׽�Ʈ�ڵ带 0��, 1��, 1�� �̻��� �� �� �����°� �� ������ �� ����.



## Action Item

> �׽�Ʈ�ڵ带 �ۼ��Ҷ� ������ �� ������ ����.

