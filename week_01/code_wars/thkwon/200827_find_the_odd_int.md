# Find the odd int

## 문제 설명

*   sequence 중에 홀수번 나온 수를 찾아서 리턴한다

## 나의 풀이 방법

```python
from collections import Counter
import unittest


def find_it(seq):
    counter = Counter(seq)
    return [key for key in counter if counter[key] % 2][0]


class TestFindIt(unittest.TestCase):
    def test_find_it_should_return_element_of_seq_when_seq_length_is_one(self):
        self.assertEqual(find_it([10]), 10)

    def test_find_it_common_case(self):
        self.assertEqual(find_it([1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5]), -1)

```

*   리스트 내의 숫자들의 개수를 세는 것이기 때문에 바로 `Counter` 를 사용하였다.
*   `Counter` 를 사용했을 때, 매우 쉽게 풀 수 있는 문제이다
*   리스트를 생성하지 않는 방법으로 할 수 있지 않을까 해서 많이 고민하였는데, 일단 답을 보기로 하였다.

## 다른 사람의 풀이 방법

### Best Practice

```python
def find_it(seq):
    return next(x for x in set(seq) if seq.count(x) % 2)
```

*   나의 개인적인 베스트 프랙티스는 위 코드라고 생각한다.
*   내가 쓴 답처럼 굳이 Counter 를 만들고, 리스트를 생성해서 인덱스로 반환할 필요 없이 generator comprehension을 생성 후, 조건에 맞는 값일 때, next로 바로 리턴해버리는 방법이 메모리 측면에서나 성능측면에서 제일 베스트 하다고 생각하고 파이써닉 적인 풀이법이라고 생각한다.

###Clever

```python
import operator

def find_it(xs):
    return reduce(operator.xor, xs)
```

*   operator 와 reduce 를 사용하는 방법이 제일 Clever 하다고 느꼈다
*   함수형 프로그래밍에 익숙하지 않다보니. reduce 로 적힌 코드를 봤을 때, 직관적으로 코드가 읽히진 않지만, 파이썬 내에서 함수형 프로그래밍을 지원하는 메소드들에 대해서도 잘 알아두어야 하기 때문에, 문제풀면서 하나씩 나올 때마다 정리해두는 것이 필요할 것 같다
*   이 문서에서 정리해보려고 했으나 비트연산자에 대해서 지식이 부족하여.. 다른 문서에서 작업하려고 한다

## 배운 점

*   불필요한 변수와 리스트를 생성하지 않고 generator comprehension과 next 를 이용해서 문제 푸는 법을 배웠다

## 반성할 점

*   분명 내가 풀고 있는 방식에 문제가 있음을 느꼈음에도 해결하지 못한게 아쉬웠다

## Action Item

*   위에서 배운 것을 패턴화 시켜서, 굳이 리스트를 만들 필요가 없이 바로 return 해야하는 상황에서는 패턴화된 풀이를 쓰도록 하자