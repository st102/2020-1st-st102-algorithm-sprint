# Get the middle character

## 문제 설명

*   짝수 / 홀수에 따라서 문자열을 가운데 부분을 리턴한다.

## 나의 풀이 방법

```python
import unittest


def get_middle(s):

    def get_mid_index():
        return len(s) // 2

    if len(s) % 2:
        return s[get_mid_index()]

    return s[get_mid_index() - 1:get_mid_index() + 1]


class TestGetMiddle(unittest.TestCase):
    def test_get_middle_given_s_is_odd(self):
        self.assertEqual(get_middle("testing"), "t")

    def test_get_middle_given_s_is_even(self):
        self.assertEqual(get_middle("middle"), "dd")
```

*   이 문제의 케이스는 크게 2가지로 나뉜다.
    *   짝수일 때는 가운데 2개의 character 를 리턴
    *   홀수 일 때는 가운데 1개의 character를 리턴
*   이것에 대한 테스트케이스가 충족하면 모든 경우가 커버가 된다.

## 다른 사람의 풀이 방법

### Best Practice

```python
def get_middle(s):
   return s[(len(s)-1)/2:len(s)/2+1]
```

*   1개의 리턴 문으로 문제를 풀었는데 풀이법이 신기 하지만, 가독성은 영 꽝이다
*   이 문제를 보았을 때, 고민 없이 홀수 경우와 짝수 경우를 나누어서 풀어야 겠다라고 생각하고 풀었는데 이렇게 풀어볼 발생은 하지 못하였다.
*   발상이 좋은 것 정도로 배우면 좋을 것 같다

###Clever

```python
def get_middle(s):
    index, odd = divmod(len(s), 2)
    return s[index] if odd else s[index - 1:index + 1]
```

*   코드워즈 문제를 풀다보면, `divmod` 를 자주 볼 수 있다 
*   몫과 나머지를 리턴해주는데, 위 식에서는 string 길이를 2로 나누었을 때의 몫과 나머지를 index, odd 변수로 받았다
*   베스트 프랙티스 코드 보다 위 코드가 훨씬 깔끔하고 명확하다
*   위 코드를 굳이 좀 고치자면,

```python
def get_middle(s):
    index, is_odd = divmod(len(s), 2)
    return s[index] if is_odd else s[index - 1:index + 1]
```

* 이렇게 써주면 훨씬 더 가독성에 도움이 된다.

## 배운 점

*   `divmod` 를 꼭 몫을 구하고 나머지를 구할 때만 쓰지 않아도 된다. 비슷하게 활용할 수 있는 문제가 있다면 적극 활용하였을 때, 가독성에 매우 도움을 받을 수 있음을 배웠다

## 반성할 점

*   최대한 가독성에 신경쓰면서 코드를 작성하는데, 좀 더 파이써닉 적으로 가독성을 좋게 할 수 있는 방법에 대한 고민이 더 필요하다(`divmod` 를 활용하는 것등등)

## Action Item

*   몫과 나머지 나오는 문제를 제외하고도,`divmod` 를 적극 활용해보자