# 02주차 List Filtering- Python

## 문제 설명
* 입력받은 배열에서 정수형 원소만 추출한다.

## 풀이방법
```python
import unittest


def filter_list(l):
    return [item for item in l if isinstance(item, int)]


class TestFilterList(unittest.TestCase):
    def test_filter_list_with_str_list(self):
        self.assertEqual(filter_list(["hello", "world"]), [])
    def test_filter_list_with_int_list(self):
        self.assertEqual(filter_list([1, 2, 3, 4]), [1, 2, 3, 4])
    def test_filter_list_with_mixed_list(self):
        self.assertEqual(filter_list([1, 2, 3, "1", "2"]), [1, 2, 3])


if __name__ == "__main__":
    unittest.main()
```
* isinstance()를 통해 int형만 골라냈다.
* test를 처음 작성해 보았는데 vscode에서는 영상과 다르게 main을 만들어줘야 동작하는 것 같다.
* str만 있는 list를 테스트하고 int만 있는 list를 테스트한 후에 합쳐진 경우를 테스트 했다.
* 이때까지 print와 디버깅을 통해 값을 확인하고 논리가 맞는지 확인했지만 이런식으로 작성해보니 어떤 코드인지 남들이 봐도 쉬울 것 같다.

## 다른사람의 풀이방법

### Best practice
```python
def filter_list(l):
  'return a new list with the strings filtered out'
  return [i for i in l if not isinstance(i, str)]
```
* 같은 방식이지만 str이 아닐 경우에 list에 저장했다.

### Clever
```python
def filter_list(l):
    return filter(lambda x: not type(x) is str, l)
```
* filter()를 이용해 str이 아닐 때를 골라냈다.
* type을 이용하여 자료형을 알아냈다.

## 배운점
* filter, isinstance, type과 같은 내장함수

## 반성할점
* 이번 문제에서 반성할 점은 없다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.