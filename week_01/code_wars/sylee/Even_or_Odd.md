# Even or Odd

## 문제설명

> 수가 하나 주어지고 짝수이면 'Even'을 홀수이면 'Odd'를 출력하는 함수를 제작

## 나의 풀이 방법

 ```python
def even_or_odd(number):
    x="Odd"
    y="Even"
    return x if(number%2) else y
 ```

> 처음작성 코드이다.  Best Practices에 더 좋은 코드가 있을 거 같아 고민해보았지만 
>
> 여기서 더 이상 획기적인 방법이 떠오르지 않았다.




## 다른 사람의 풀이 방법

```python
# Best Practices

def even_or_odd(number):
    return 'Odd' if number % 2 else 'Even'
```

> 내 코드와 유사하다.  변수 이외에 바로 문자열이 들어갈 수 있는지 몰랐었다.
>
> 만약 알았더라면 이렇게 했었을 것 같다.



```python
# Clever
def even_or_odd(number):
  return ["Even", "Odd"][number % 2]
```

 > list comprehension을 이용한 것 같다. 되게 신선한 방법같아 보였다.



```python
# Clever
even_or_odd = lambda number: "Odd" if number % 2 else "Even"
```

> 새로 보는 문법이었다. 구성은 Best Practices와 같아 보였다.



## 배운 점

>  `return 'Odd'`처럼  return값이 변수가 아닌 문자열을 넣을  수 있다는 것을 알게 되었다.	

> `lambda`에 대해서 알게 되었다. `:` 앞에는 변수(들)를 뒤에는 `return` 값을 작성한다.

## 반성할 점

> Python의 문법적인 부분 중에서 놓치고 있는 부분들이 있는 것 같다. 복습해봐야 겠다.

## Action Item

> generator & list comprehension에 익숙해지기.