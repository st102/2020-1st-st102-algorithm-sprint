# 01주차 Find the odd int

## 풀이방법
```python
def find_it(seq):
    for n in seq:
        if seq.count(n) % 2:
            return n
```
* 입력된 list의 첫번째 값부터 개수를 센다.
* 해당 값의 개수가 홀수일 경우 return하여 반복문을 중단한다.
* list의 size가 클 때 모든 index의 개수를 구하기 때문에 시간이 오래 걸릴 것 같다.

## 다른사람의 풀이방법

### Best practice
```python
def find_it(seq):
    for i in seq:
        if seq.count(i)%2!=0:
            return i
```
* 나와 같은 방법이지만 if문에서 내 코드가 좀 더 간결하다.

### Best practice
```python
def find_it(seq):
    for elem in set(seq):
        if seq.count(elem):
            return elem
```
* 내 생각엔 이 코드가 best라고 생각한다. 
* set()을 사용하여 input list의 모든 값을 탐색하지 않고 중복을 제외하여 탐색하므로 연산시간을 단축시킬 수 있다.

### Clever
```python
from functools import reduce
import operator
def find_it(xs):
    return reduce(operator.xor, xs)
```
* python3부터는 reduce가 내장함수가 아니기 때문에 ```from functools import reduce```를 써주어야 한다.
* reduce 함수를 xor function을 이용하여 xs list에서 짝지어질 수 있는 수를 0으로 치환한다. 결과적으로 홀수개의 수를 갖는 값만 남게된다.

```python
from functools import reduce
def find_it(xs):
    return reduce(lambda x, y : x ^ y, xs)
```
* 위처럼 lambda expression으로 operator 모듈을 import하지 않고 작성 가능하다.
* clever하지만 직관적이지 않은 것 같다.

## 배운점
* reduce()의 사용법

## 반성할점
* 단순한 코드라도 연산속도를 고려하며 코드를 짜야겠다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.