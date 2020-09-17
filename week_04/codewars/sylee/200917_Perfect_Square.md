# Find the next perfect square!

## 문제설명

> 정수를 하나 받아 이진수로 변환했을 때, 1의 개수를 반환

 ```python
import math


def find_next_square(sq):
    root = math.sqrt(sq)
    return -1 if root % 1 else (root + 1) ** 2


class TestFindNextSquare(unittest.TestCase):
    def test_not_perfect_square(self):
        self.assertEqual(find_next_square(111), -1)

    def test_perfect_sqaure(self):
        self.assertEqual(find_next_square(121), 144)
 ```

> 제곱근 구하는 메소드 `sqrt()`를 사용했다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def find_next_square(sq):
    root = sq ** 0.5
    if root.is_integer():
        return (root + 1)**2
    return -1.
```



```python
# Best Practices 2
def find_next_square(sq):
    x = sq**0.5    
    return -1 if x % 1 else (x+1)**2
```

> 위 두가지를 합쳐서
>
> ```python
> def find_next_square(sq):
>     x = sq**0.5    
>     return (x+1)**2 if x.is_integer() else -1
> ```
>
> 이렇게 만들면 좋을 것 같다.





## 배운 점

>  `is_integer()`메소드를 알게 되었다.



## 반성할 점

> 특별히 없었다고 생각한다.



## Action Item

> .

