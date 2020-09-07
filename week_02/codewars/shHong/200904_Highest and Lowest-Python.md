# 02주차 Highest and Lowest - Python
## 문제 설명
* 공백으로 구분된 정수의 문자열에서 최대, 최소값을 문자열로 리턴한다.

## 풀이방법
```python
def high_and_low(numbers):
    nums = list(map(int, numbers.split()))
    return "{} {}".format(max(nums), min(nums))
```
* map()을 이용하여 문자열 분리 후 int형으로 mapping했다.
* max와 min으로 정수list에서 값을 가져왔다.

## 다른사람의 풀이방법

### Best practice
```python
def high_and_low(numbers): #z.
    nn = [int(s) for s in numbers.split(" ")]
    return "%i %i" % (max(nn),min(nn))
```
* list comprehension을 이용하여 문자열을 정수list로 바꿨다.


### Clever
```python
def high_and_low(numbers):
  return " ".join(x(numbers.split(), key=int) for x in (max, min))
```
* 다른 풀이는 거의 내 풀이랑 비슷했지만 이 풀이방법은 독특했다.
* max(iterable, *, default=obj, key=func) 이러한 인자를 받지만 위처럼 밖으로 빼서 표현이 가능하다는 것을 알았다.

## 배운점
* clever처럼 짜는 법? 좋은 것 같지는 않아 보인다.

## 반성할점
* 이번 문제에서 반성할 점은 없다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.