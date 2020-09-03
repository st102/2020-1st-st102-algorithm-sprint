# 02주차 Create Phone Number - Python

## 풀이방법
```python
def create_phone_number(n):
    return "({0}) {1}-{2}".format(join(n[:3]),join(n[3:6]),join(n[6:]))
def join(s):
    return "".join(map(str, s))
```
* integer list를 string으로 변환하는 과정을 join()으로 묶었다.

## 다른사람의 풀이방법

### Best practice
```python
def create_phone_number(n):
    return "({}{}{}) {}{}{}-{}{}{}{}".format(*n)
```
* 별도의 문자열 변환과정을 생략했다. format(*args)를 이용하여 풀었다.

### Clever
```python
def create_phone_number(n):
    n = ''.join(map(str,n))
    return '(%s) %s-%s'%(n[:3], n[3:6], n[6:])
```
* 내 풀이와 비슷하지만 입력된 문자열을 string으로 먼저 변환했다.

## 배운점
* 몰랐던 것을 알게 된 경우는 없다.

## 반성할점
* 간단한 문제를 더 간단하게 풀 방법을 생각해야겠다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.