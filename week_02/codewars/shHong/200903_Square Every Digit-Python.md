# 02주차 Square Every Digits - Python
## 문제 설명
* 정수를 입력받아 각 자리수의 제곱을 구하여 합한다.

## 풀이방법
```python
def square_digits(num):
    return int("".join(str(int(n) ** 2) for n in str(num)))
```
* 입력받은 정수를 string으로 변환 후 제곱하여 join 했다.

## 다른사람의 풀이방법

### Best practice
```python
def square_digits(num):
    ret = ""
    for x in str(num):
        ret += str(int(x)**2)
    return int(ret)
```
* 문자열을 더하는 방식으로 구현했다.

### Clever
```python
def square_digits(num):
    return int(''.join(str(int(d)**2) for d in str(num)))
```
* 내 풀이와 같다.

## 배운점
* 몰랐던 것을 알게 된 경우는 없다.

## 반성할점
* 이번 문제에서 반성할 점은 없다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
