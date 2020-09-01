# 02주차 Sum of Digits / Digital Root - Python

## 풀이방법
```python
def digital_root(n):
    number = str(n)
    while len(number) != 1:
        number = str(sum(int(num) for num in number))
    return int(number)
```
* input number의 길이가 1이 될 때 까지 number를 split해서 더한다.

## 다른사람의 풀이방법

### Best practice
```python
def digital_root(n):
    return n if n < 10 else digital_root(sum(map(int,str(n))))
```
* n이 한자리수가 될 때까지 재귀적으로 실행한다.
* map 함수를 이용하여 n을 int형 iterator로 변환해서 합을 구했다.
* 재귀함수는 지양하는 것이 좋지만 표현력이 좋아지는 장점이 있다.

### Clever
```python
def digital_root(n):
    return n%9 or n and 9 
```
* n % 9의 값이 위의 함수와 동일하다는 것을 알았다. 수학적인 접근으로 연산시간을 단축하고 간결해졌다.
* bool 연산으로 한자리인 경우와 나누어 떨어지는 경우를 포함시켰다.

## 배운점
* 재귀함수
* and, or와 같은 bool 연산

## 반성할점
* C스러운 코드와 필요없는 변수의 선언

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 유용할 수 있는 함수의 사용법 찾아보기.