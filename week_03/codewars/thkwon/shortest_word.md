# Shortest Word

## 문제 설명

* 띄어쓰기로 이루어진 string에서 가장 길이가 작은 단어의 길이를 리턴한다.



## 나의 풀이 방법

```python
import unittest


def find_short(s):
    return min(map(len, s.split()))


class TestFindShort(unittest.TestCase):
    def test_find_short(self):
        self.assertEqual(find_short('bitcoin take over the world maybe who knows perhaps'), 3)
```

*  map() 을 이용해서, 검사하려는 list를 `len` 을 기준으로 만들어준 후, 그 중 최소 값을 리턴하였다.
*  테스트는 어떤 엣지케이스가 없었기 때문에 common 한 케이스에 대해서 테스트 해도 된다고 판단하였고, 메소드 명도 common하게 지어주었다.

## 다른 사람의 풀이 방법

* ### Best Practice

  ```python
  def find_short(s):
      return min(len(x) for x in s.split())
  ```
  
* generator comprehension으로 길이 기준으로 생성 후, 거기서 최소 값을 구한다
  * 문제를 풀 때, map에 대해서 많이 풀다보니 자연스럽게 map을 써서 풀었는데 사실 이 문제는 위의 풀이가 실제 현업 코드에서도 많이 쓰인다



* ### Clever

  ```python
  def find_short(s):
      return len(min(s.split(' '), key=len))
  ```

  * min을 수행할 때, Key를 적용하여서 어떤 기준에 따라 min 값을 리턴할 것인지 정해줄 수 있다.
  * 위는 길이를 기준으로 길이가 가장 짧은 단어의 길이를 구하여 리턴한다.


## 배운 점

*   `min` 의 사용법(key 활용)
*   map / generator expression의 활용

## 반성할 점

*   generator expression으로 표현이 가능하다면, map 보단, generator expression을 쓰자

## Action Item

*   map으로 풀 수 있다면, generator expression으로 풀어서 써보자

