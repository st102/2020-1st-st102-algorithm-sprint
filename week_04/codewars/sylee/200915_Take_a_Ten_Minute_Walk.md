# Take a Ten Minute Walk

## 문제설명

> 각 방향을 나타내는 알파벳 n,s,w,e 가 주어지고 이 알파벳들의 합이 10이면서 이동 후 원점으로 오게되면 True 아니면 False를 리턴하는 함수를 만들기

## 나의 풀이 방법

 ```python
import unittest


def is_valid_walk(walk):
    return (
        True
        if len(walk) == 10
        and walk.count("s") == walk.count("n")
        and walk.count("e") == walk.count("w")
        else False
    )


class MyTestCase(unittest.TestCase):
    def test_length_is_not_ten(self):
        self.assertEqual(
            is_valid_walk(["w", "e", "w", "e", "w", "e", "w", "e", "w", "e", "w", "e"]),
            False,
        )

    def test_length_is_ten(self):
        self.assertEqual(
            is_valid_walk(["n", "s", "n", "s", "n", "s", "n", "s", "n", "s"]), True
        )
        self.assertEqual(
            is_valid_walk(["w", "e", "w", "e", "w", "e", "w", "e", "w", "e"]), True
        )
        self.assertEqual(
            is_valid_walk(["w", "e", "s", "s", "s", "e", "e", "e", "w", "e"]), False
        )

 ```

> 1. 방향의 개수가 10이 아닐때	-	False
> 2. 방향의 개수가 10일때
>    - 이동 후 원점일 때	-	True
>    - 이동 후 원점이 아닐 때 	-	False

> 위와 같은 메커니즘으로 테스트 기준을 정했다. 




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def isValidWalk(walk):
    return len(walk) == 10 and walk.count('n') == walk.count('s') and walk.count('e') == walk.count('w')
```

> 나와 거의 비슷하지만 차이점은  `And`연산 자체로 `True`, `False`를 반환했다.



## 배운 점

>  조건의 성공, 실패 자체로 True, False를 반환하기.



## 반성할 점

> 특별히 반성 할 점이 없는 것 같다.



## Action Item

> TDD, 테스트코드