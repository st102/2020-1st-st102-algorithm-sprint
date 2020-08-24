# 01주차 모음 갯수 출력

## 풀이방법
```python
def get_count(input_str):
    num_vowels = 0
    for s in input_str:
        if s in 'aeiou':
            num_vowels += 1
    return num_vowels

print(get_count(input()))
```
* 입력된 문자열의 처음부터 비교합니다. 모음이 있는 경우 num_vowels++ 합니다.
* codewars에는 get_count()만 제출했습니다.

## 다른사람의 풀이방법
```python
def getCount(s):
return sum(c in 'aeiou' for c in s)
```
* 훨씬 간단하고 파이썬스럽다. 
> Starting with the inner comprehension: (c in 'aeiou' for c in s)
> 
> This iterates through each character c in the input string s, checking if c is one of the characters in 'aeiou'. The in operator (c in 'aeiou') returns a boolean (True/False).

> A boolean can be treated by Python as an integer value: 1 for True, 0 for False.

>The sum function will return the sum (all of the terms added together) of the comprehension. Since, as explained above, the value is 1 when the character is a vowel, and 0 when the character is not a vowel, this sum will be equal to the total number of vowels in the input string.
* sum()의 인자로 boolean generator를 삽입하여 구현했다.

## 배운점
* generator expression에 대해 알게 되었다(명칭과 사용법)

## 반성할점
* python이라는 언어를 사용하면서 아직 C-like한 코드를 짜는 것 같다.
* 다른 언어로 짜려면 귀찮을 것 같다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
