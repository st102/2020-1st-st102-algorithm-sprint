# Bit Counting

## 문제설명

> 정수를 하나 받아 이진수로 변환했을 때, 1의 개수를 반환

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

> codewars에 있는 테스트 코드를 사용했는데,  0일 때와 0이 아닐때 두가지 케이스 정도만
>
> 검사해도 될 것 같다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def countBits(n):
    return bin(n).count("1")
```

> 문제 이름도 `Counting`인데 나는 왜 `sum()`을 이용했는지 모르겠다. ㅋㅋ
>
> `count()`를 이용하면 더 간결해진다.



```python
# Best Practices 2
def countBits(n):
    return '{:b}'.format(n).count('1')
```

> `{:b}`를 이용하여 2진수로 만들 수 있다는 것을 알았다.
>
> 추가로 `format(n, 'b').count('1')`로도 쓸 수 있다.





## 배운 점

>  format을 이용한 진수 변환을 알게 되었다.



## 반성할 점

> 문제설명보다 예제를 보고 문제를 이해한 것 같다.



## Action Item

> 문제 잘 이해하기

