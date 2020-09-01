# Sum of Digits / Digital Root

## 문제설명

> 자연수 n 이 주어지고, n의 각 자리수의 합을 구한다. 합이 한 자리수가 나올 때 까지 계속한다.

## 나의 풀이 방법

 ```python
def digital_root(n):
    list_a = [x for x in str(n)]
    result_a = sum(int(x) for x in list_a)

    if result_a >= 10:
        return digital_root(result_a)
    return result_a
 ```

> 처음작성 코드이다.  각 자리를 리스트의 원소로 만들어 합을 구한다. 
>
> 결과에 따라 함수를 다시 재귀하거나 바로 끝낸다.



```python
def digital_root(n):
    result_a = sum(int(x) for x in str(n))
    return result_a if result_a < 10 else digital_root(result_a)
```

>위 코드에서 수정 할 부분을 수정했다. 

1. 굳이 리스트를 사용할 필요가 있나 싶어 없앴다.

2. if문을  간결하게 수정했다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def digital_root(n):
    return n if n < 10 else digital_root(sum(map(int,str(n))))
```

> 내 제출 코드에서 더 간결하게 만든 느낌이다.
>
> 작동 방식은 내 코드와 비슷한 것 같다.



```python
# Clever
def digital_root(n):
    return n%9 or n and 9 
```

 > 이건 굉장히 획기적인 방법인것 같다.

> `return n%9`에서는 n이 0이거나 9의 배수인 경우를 제외하고 결과를 도출 해 낼 수 있다.

> `n and 9`에서는 n이 0이면 0을 9의 배수이면 9를 반환한다.
>
> >  `A and B`를 해보면 A와 B중에서 작은 값이 나오는 것 같다.



## 배운 점

>  `or` 과 `and`에 대해 알게 되었다.
>
>  > 그 동안은 조건 식으로만 이용해서 0 또는 0이 아님에 대해서만 고려 했는데
>  >
>  > 이번 문제를 통해 어떤 값이 반환되는지 알게 된 것 같다.



## 반성할 점

> 지난 번에 수학적원리를 이용 할 수 있으면 해보자라고 했는데, 그러지 못했다.

## Action Item

> 수와 밀접한 관련이 있다면 일반식을 한번 세워보자. 