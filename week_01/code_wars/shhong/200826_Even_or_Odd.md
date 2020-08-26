# 01주차 Even or Odd

## 풀이방법
```python
def even_or_odd(number):
    return "Odd" if number % 2 else "Even"
```
* one-line 하게 if문 작성했다.

## 다른사람의 풀이방법

### best practice
```python
def even_or_odd(number):
    return "Odd" if number % 2 else "Even"
```
* 내가 best한 방법으로 풀었다.

### clever
```python
def even_or_odd(number):
      return ["Even", "Odd"][number % 2]
```
* 처음 이 풀이를 보았을 때 이해가 가질 않았다. 이 코드의 설명을 보니 string의 list를 표현한 것이었다.
* number % 2 가 0일 때 ["Even", "Odd"]라는 list의 0번 index인 "Even"을 의미한다.
* python이기에 가능한 코드라고 생각한다.

## 배운점
* list를 변수에 저장해서 특정 index의 값을 꺼내는 방식을 clever코드처럼 단순하게도 표현이 가능할 수 있다는 것을 알았다.

## 반성할점
* 오늘문제는 반성하지 않아도 된다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
