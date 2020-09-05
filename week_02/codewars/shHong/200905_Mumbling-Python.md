# 02주차 Mumbling - Python
## 문제 설명
* 공백으로 구분된 정수의 문자열에서 최대, 최소값을 문자열로 리턴한다.

## 풀이방법
```python
def accum(s):
    return "-".join(c.upper() + c * i for i, c in enumerate(s.lower()))
```
* enumerate를 이용하여 index와 element 접근을 동시에 했다.

## 다른사람의 풀이방법

### Best practice
```python
def accum(s):
    return '-'.join(c.upper() + c.lower() * i for i, c in enumerate(s))
```
* 나와 같은 방식으로 풀었다.


### Clever
```python
def accum(s):
    return '-'.join((a * i).title() for i, a in enumerate(s, 1))
```
* title 메서드를 이용하여 첫 문자를 대문자로 바꿨다.

## 배운점
* title()메서드: 이런 기능까지 제공해주는 파이썬 최고 ㅎ

## 반성할점
* 이번 문제에서 반성할 점은 없다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.