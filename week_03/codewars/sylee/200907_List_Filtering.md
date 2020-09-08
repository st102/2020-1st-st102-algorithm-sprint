# List Filtering

## 문제설명

>  정수와 문자가 섞인 리스트가 주어지고, 정수만을 포함한 리스트를 출력한다.

## 나의 풀이 방법

 ```python
# 과정 1
import unittest


def filter_list(l):
    return l


class TestFilter(unittest.TestCase):
    def test_should_fail_when_given_only_int(self):
        self.assertEqual(filter_list([1, 2, 3]), [1, 2, 3])
 ```

> 첫 번째로 정수(integer)만 포함한 경우를 테스트한다. (`self.fail`은 생략했다.)

- RED

  - ```python
    def filter_list(l):
        return
    ```

  - 실행 결과가 실패로 나왔다.

- GREEN

  - ```python
    def filter_list(l):
        return l
    ```

  - 실행 결과 성공이 나왔다.

- REFATOR

  - 특별히 리팩토링 사항이 없다.



```python
# 과정 2 (최종)
import unittest


def filter_list(l):
    return [element for element in l if type(element) == type(1)]


class TestFilter(unittest.TestCase):
    def test_should_fail_when_given_only_int(self):
        self.assertEqual(filter_list([1, 2, 3]), [1, 2, 3])

    def test_should_fail_when_given_int_with_string(self):
        self.assertEqual(filter_list([1, "2", 3]), [1, 3])
```

>두 번째로 정수와 문자가 섞인 리스트를 넣어 정수만 담긴 리스트가 출력돼야 한다.

- RED

  - ```python
    def filter_list(l):
        return l
    ```

  - 실행 결과가 실패로 나왔다.

- GREEN

  - ```python
    def filter_list(l):
        return return [element for element in l if type(element) == type(1)]
    ```

  - 실행 결과 성공이 나왔다.

- REFATOR

  - 특별히 리팩토링 사항이 없다고 생각했다.






## 다른 사람의 풀이 방법

```python
# Best Practices 1
def filter_list(l):
    return [i for i in l if not isinstance(i, str)]
```

> `isinstance()`메소드를 알게 되었다.
>
> 근데 `return [i for i in l if isinstance(i, int)]` 로 하면 더 직관적이고 간단한거 아닌가?
>
> > `str이 아니면 넣는다` 보다는 ` int이면 넣는다 `가 더 직관적인것 같다.



```python
# Best Practices 2
def filter_list(l):
  return [x for x in l if type(x) is not str]
```

> `A is B`문법을 잊고 있었다. 사실 내 코드에서 `if type(element) == type(1)`로 검사하는 것 보다
>
> `if type(x) is not str`로 하는 것이 더 낫다.
>
> 하지만 이 역시도 `if type(x) is int`가 더 좋다.



## 배운 점

>  `A is B` => `True or False`

> `isinstance()`



## 반성할 점

> 기본 문법사항을 잊고 있었다.



## Action Item

> TDD방식으로 계속 해보기 