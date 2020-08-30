# 01주차 Disemvowel Trolls - Python

## 풀이방법
### 이전 풀이방법
```python
def disemvowel(string):
    temp = []
    for s in string:
        if s not in ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'):
            temp.append(s)
    str = ''.join(temp)
    return str
```
* 파이썬에 대해 익혀갈 때 작성했던 코드이다.
* pythonic하지 않고 필요없는 변수선언이 많다.

### 현재 풀이방법
```python
def disemvowel(string):
    return "".join(s for s in string if s not in "aeiouAEIOU")
```
* iterator comprehension과 join을 이용하여 간결하게 작성할 수 있다.
* 과거의 코드보다 가독성이 좋고 필요없는 변수의 선언이 없다. 
* 파이썬에 대해 좀 더 이해한 듯 하다.

## 다른사람의 풀이방법

### Best practice
```python
def disemvowel(s):
    return s.translate(None, "aeiouAEIOU")
```
* translate를 이용하여 간결하게 작성했다.
* best일 수 밖에 없는 코드.

### Clever
```python
def disemvowel(string):
    return "".join(c for c in string if c.lower() not in "aeiou")
```
* 내가 작성한 코드와 비슷하지만 입력된 문자를 소문자로 변환 후 비교한다.
* 모음 비교횟수가 줄어 실행속도가 약간 더 빠를 것 같다.

## 배운점
* translate의 활용법 
* https://riptutorial.com/ko/python/example/5159/str-translate---%EB%AC%B8%EC%9E%90%EC%97%B4%EC%9D%98-%EB%AC%B8%EC%9E%90-%EB%B3%80%ED%99%98

## 반성할점
* 더 많은 함수의 사용법을 익혀야겠다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 유용할 수 있는 함수의 사용법 찾아보기.