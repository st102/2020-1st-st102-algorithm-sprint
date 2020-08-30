

# Disemvowel Trolls

## 문제설명

> 주어진 문자열에서 모음문자를 없앤 문자열을 출력하기.

## 나의 풀이 방법

```python
# 처음풀이
def disemvowel(string):
    string = list(string)

    for elem in string:
        if elem in "aeiouAEIOU":
            string.remove(elem)
    string = "".join(string)
    return string

```

> Test case는 성공했지만 제출에는 실패했다. 생각해보니 모음이 연속으로 오는 경우, 실패하는 것 같았다.



 ```python
# 제출성공
def disemvowel(string):
    string = list(string)

    for element in "aeiouAEIOU":
        while element in string:
            string.remove(element)
    string = "".join(string)
    return string

 ```

> 저번 피드백으로 remove() 메소드사용을 지양하라고 하셨는데,  다른 방법이 도무지 생각나지 않았다.
>
> 그리고 처음 답안을 작성했을 때, 처음 답안이 비효율적인것 같거나 더 간단한 방법으로 작성하기 위해 다른방법을 생각해본다. 하지만 계속 처음 방식만 생각나고 다른 방식을 생각하기 어렵다.
>
> 사고가 제한되는 것 같다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def disemvowel(string):
    return string.translate(None, "aeiouAEIOU")
```

> `translate() ` 라는 메소드를 이용했다. Python3에서 돌려봤더니 error가 난다. 
>
> 1개의 argument만 입력받는데 두 개를 받아서 error가 출력되었다. 다른 버전인가 보다.
>
> 추가적으로 `maketrans()`메소드를 알아보고 그냥 넘어갔다.



```python
# Best Practices 2
def disemvowel(s):
    for i in "aeiouAEIOU":
        s = s.replace(i,'')
    return s
```

> `replace()`메소드를 이용해 모음을 공백으로 치환한다. 치환 후 다시 저장하여 모든 모음에 대해 적용한다.



```python
# Best Practices 3
def disemvowel(string):
    return "".join(c for c in string if c.lower() not in "aeiou")
```

 > 이 풀이가 Best라고 생각한다.  문자가 모음이 아닐경우에 join하고 아닐경우엔 그냥 넘어가는 방식인거같다.
 >
 > `c.lower()`을 사용해 `aeiouAEIOU` 대신 `aeiou` 와 비교했다.
 >
 > 굳이 `remove()`같은 메소드나 `maketrans()`같은 메소드를 사용해 삭제나 치환하는 것이 아니라 배제할 수도 있음을 배웠다.



## 배운 점

>  `maketrans()`, `lower()`, `replace()` 메소드에 대해 알게 되었다

> `return a new string with all vowels removed.` 라고 문제설명에 나와있는데,
>
> `return a new string without vowels`라고도 생각할 수 있어야 겠다.



## 반성할 점

> 알고 있는 기본 지식이 부족하여, 다른 방법으로 생각하는 것도 제한되는 것 같다.

## Action Item

> 문제의 의미를 재해석(?) 해보기.