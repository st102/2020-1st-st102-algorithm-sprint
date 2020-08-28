# 01주차 Get the middle character

## 풀이방법
```python
def get_middle(s):
    return s[len(s) // 2] if len(s) % 2 else s[len(s) // 2 - 1 : len(s) // 2 + 1]
```
* string의 길이가 홀수일 때, 짝수일 때를 나누어 출력한다.
* 짝수일 때 중간 문자 두개만 slice하여 출력한다.

## 다른사람의 풀이방법

### Best practice & Clever
```python
def get_middle(s):
   return s[(len(s)-1)//2:len(s)//2+1]
```
* 나머지 코드는 그다지 clever한 것 같지 않다.
* 홀수, 짝수 모든경우를 한줄로 표현하여 간결하다.
* 코드는 간결하지만 직관성은 떨어진다고 생각한다.

## 배운점
* 수학적인 접근을 통한 간결한 표현

## 반성할점
* 반성할 점은 없는 것 같다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.