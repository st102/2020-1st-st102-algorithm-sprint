# List Filtering

## 문제 설명

* 주어진 리스트에서 숫자 값을 판별하여 필터링 한다.



## 나의 풀이 방법

```python
import unittest


def filter_list(given_list):
    return [element for element in given_list if isinstance(element, int)]


class TestFilterList(unittest.TestCase):
    def test_filter_list(self):
        self.assertEqual(filter_list([1, 2, 'a', 'b']), [1, 2])

```

*  주어진 리스트의 요소 값이 int 인지 필터링 하는 list comprehension을 리턴한다.
* 이 문제의 경우는 엣지 케이스들을 처리하는 것에 대한 명시가 없어서 common case에 대한 테스트 1개만 만들어 주었다.

## 다른 사람의 풀이 방법

* ### Best Practice

  ```python
  def filter_list(l):
    'return a new list with the strings filtered out'
    return [i for i in l if not isinstance(i, str)]
  ```

  * 이게 베스트 프랙티스 이긴 한데, not을 붙이는 것보다, int로 검사하고, not을 빼는 것이 더 좋은 방법 같다.



* ### Clever

  ```python
  def filter_list(l):
      return filter(lambda x: not type(x) is str, l)
  ```

  * > function 에는 일반적인 function 을 정의하여 사용할수도 있지만, 간단한 조건의 경우에는 [lambda](https://bluese05.tistory.com/63)를 함께 사용하면 굉장히 간결한 형태로 작성 가능하다.
    >
    > 출처: https://bluese05.tistory.com/66 [ㅍㅍㅋㄷ]

  * ```python
    def filter_list(given_list):
        return list(filter(lambda element: isinstance(element, int), given_list))
    ```

    * 위 clever 답을 내 코드에 맞게 다시 고쳐보면, 위와 같이 표현 할 수 있을 것 같다.
    * 사실은 filter라는 내장 함수를 사용할 필요 없이 list comprehension으로 충분히 표현이 가능한 문제이다.
    * 그러나, 위와 같이 푸는 방법에 대해서도 알아두면 좋을 것 같다.


## 배운 점

*   `filter` 내장 함수 사용법

## 반성할 점

*   반성할 점은 딱히 없다

## Action Item

*   list comprehension 문제를 풀 때, 내부에서 필터해야하는 문제가 있다면, `filter` 를 활용해서도 구현해 보자.

