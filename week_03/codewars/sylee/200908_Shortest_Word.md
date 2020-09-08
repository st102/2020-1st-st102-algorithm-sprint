# Shortest Word

## 문제설명

> 문장이 주어지고, 문장 중에서 가장 짧은 단어의 길이를 반환한다.

## 나의 풀이 방법

 ```python
def find_short(s):
    return min(len(i) for i in s.split())


class Test_Short(unittest.TestCase):
    def test_shortest_is_three(self):
        self.assertEqual(
            find_short("bitcoin take over the world maybe who knows perhaps"), 3
        )

    def test_shortest_is_two(self):
        self.assertEqual(find_short("Lets all go on holiday somewhere very cold"), 2)

    def test_shortest_is_one(self):
        self.assertEqual(
            find_short("i want to travel the world writing code one day"), 1
        )

 ```

> codewars의 테스트 케이스를 그대로 쓰긴 했는데,  이번 문제는 특별히 고려할 사항이 없던 것 같다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def find_short(s):
    return min(len(x) for x in s.split())
```

> 내 코드와 동일하다.



```python
# Best Practices 2
def find_short(s):
    return len(min(s.split(' '), key=len))
```

> 저번에 봤었던 `key`를 사용해 구현했다.



## 배운 점

>  특별히 없는 것 같다.



## 반성할 점

> 특별히 반성 할 점도 없는 것 같다.



## Action Item

> TDD로 해보긴 했는데, 이번 문제는 고려사항이 많지 않았다.