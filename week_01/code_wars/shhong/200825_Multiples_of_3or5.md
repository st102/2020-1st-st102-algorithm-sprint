# 01주차 Multiples of 3 or 5

## 풀이방법
```python
def solution(number):
    total = sum(num * 3 for num in range(1, number//3 + 1) if (num * 3) < number)
    total += sum(num * 5 for num in range(1, number//5 + 1) if (num * 5) < number)
    total -= sum(num * 15 for num in range(1, number//15 + 1) if (num * 15) < number)
    return total
```
* 입력된 수 까지의 3과 5의 공배수를 더하고 15의 공배수를 뺀다.
* 반복문 횟수를 줄이기 위해 입력된 수를 3, 5, 15로 나누어 실행했다.

## 다른사람의 풀이방법

### best practice
```python
def solution(number):
    return sum(x for x in range(number) if x % 3 == 0 or x % 5 == 0)
```
* 발상은 비슷하지만 좀 더 간결하고 이해하기 쉽다.
* 1부터 input까지 증가시키면서 3,5로 나누어 떨어질 때 더하는 방식이다.
* 내 코드가 오징어처럼 보인다. 너무 복잡하게 생각한 것 같다.

### clever
```python
def solution(number):
    threes = range(3, number, 3)
    fives = range(5, number, 5)
    return sum(list(set(threes + fives)))
```
* range() 메서드에서 3, 5 간격을 지정해서 iterator를 만들고 set()메서드를 이용해 중복을 제거 후 리스트화 하여 더했다.
* 발상이 재밌고 메서드 사용의 다양한 방법을 보았다.

## 배운점
* 어제의 문제에서 iterator expression에 대해 생각했던 것을 이번문제에서 잘 사용한 것 같다.
* range() 메서드의 증감량을 정할 수 있다는 것을 다시금 알게했다.

## 반성할점
* 간단하게 생각할 수 있는 문제를 너무 어렵게 접근했다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
