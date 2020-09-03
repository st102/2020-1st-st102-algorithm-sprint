# Squared Every Digit

## 문제설명

> 정수를 입력받아 각자리를 제곱한 수를 출력 

## 나의 풀이 방법

 ```python
def square_digits(num):
    return int("".join(str(int(x) ** 2) for x in str(num)))
 ```

> 처음 풀이이다. 별 어려움 없었다.



```python
def square_digits(num):
    return int("".join(str(x ** 2) for x in map(int, str(num))))
```

> map을 이용하여 풀어보았다.



```python
def square_digits(num):
    list_square = [int(x) ** 2 for x in str(num)]
    return int(("{}" * len(list_square)).format(*list_square))
```

> *args를 이용해 풀어 보았다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def square_digits(num):
    ret = ""
    for x in str(num):
        ret += str(int(x)**2)
    return int(ret)
```

> 이 풀이를 숏코딩하면 내 풀이와 같다.



```python
# Best Practices 2
def square_digits(num):
    return int(''.join([str(n * n) for n in map(int, str(num))]))
```

> 나는 `x ** 2`로 썼는데, `x * x`가 더 보기 좋은 것 같다. 

> 여기서 굳이 리스트 `[ ]` 를 쓸 필요가 없는 것 같다. 
>
> 뒤에 `))]))`이런 식으로 끝나는데 많으면 많을수록 보기 어지러워서 하나라도 더 줄이는게 좋은 것 같다.



## 배운 점

>  특별히 없었다.



## 반성할 점

> 특별히 없었다.



## Action Item

> 간결하며 읽기쉬운 코드 만들기(사소한부분이라도)