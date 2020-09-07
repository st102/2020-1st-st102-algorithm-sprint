# Mumbling

## 문제설명

> 받은 문자열에서 첫번째 글자는 1개, 두번째 글자는 2개, ... , n번째 글자는 n개를 출력한다.
>
> 각, n개중 첫번째는 대문자로 출력한다.



## 나의 풀이 방법

 ```python
def accum(string):
    return "-".join(string[i].upper()+string[i].lower()*i for i in range(len(string)))
 ```

> 처음 풀이이다.  이번 문제는 문자열의 요소와 인덱스 값을 같이 받는다면 더 깔끔하게 짤 수 있을 것 같았다.



```python
def accum(string):
    return "-".join(
        element.upper() + element * index
        for index, element in enumerate(string.lower())
    )
```

> 요소와 인덱스를 같이 반환해주는 `enumerate()`를 사용하여 풀었다.




## 다른 사람의 풀이 방법

```python
# Best Practices
def accum(s):
    return '-'.join(c.upper() + c.lower() * i for i, c in enumerate(s))
```

> 내 풀이와 비슷하다. 아쉬운 점은 `i, c`로 변수의 이름을 단번에 이해하기 어렵다.



```python
# Clever
def accum(s):
    return '-'.join((a * i).title() for i, a in enumerate(s, 1))
```

> 첫 글자를 대문자로 출력해주는 `title()`을 이용하여 풀었다.  덕분에 더 깔끔해 보인다.
>
> `enumerate(s,1)`을 사용하여 인덱스 시작을 `0`이 아닌 `1`로 시작하는 점이 좋았다.



## 배운 점

>  다른 풀이들을 보다가 `capitalize()` 라는 메소드를 보았다. `title()`과는 비슷하지만 다르다.



>  `title()` : **각** 단어의 첫글자를 대문자로 바꿔준다.
>
>  - Ex)	`python` => `Python` ,	`hello python` => `Hello Python`



>  `capitalize()` : 첫 문자를 대문자로 바꾸어준다. ( => 첫 문자**만** 대문자로 출력한다.)
>
>  - Ex)	`python` => `Python` ,	`hello Python` => `Hello python`, 



## 반성할 점

> 특별히 없었던 것 같다.



## Action Item

> 파이썬은 다양한 method가 있는 것 같다. 비슷한 기능이어도 차이가 있다.
>
> 잘 구분해서 쓰자.

