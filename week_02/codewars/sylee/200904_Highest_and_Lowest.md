# Highest and Lowest

## 문제설명

> 받은 문자열 중 크기가 가장 큰 정수와 가장 작은 정수를 차례로 출력한다.

## 나의 풀이 방법

 ```python
def high_and_low(numbers):
    list_of_number = [x for x in numbers.split()]
    return "{} {}".format(max(list_of_number), min(list_of_number))
 ```

> 처음 풀이이다. 별 어려움 없이 성공 하는 가 싶었는데, 테스트케이스를 통과를 못했다.
>
> "4 5 29 54 4 0 -214 542 -64 1 -3 6 -6" 에서 출력이 '6 -214'로 나왔다.
>
> 리스트에 저장할 때 string type으로 저장이 돼서 542 보다 6이 더 컸던 것이다.



```python
def high_and_low(numbers):
    list_of_number = [x for x in map(int, numbers.split())]
    return "{} {}".format(max(list_of_number), min(list_of_number))
```

> map을 이용하여 수정했다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def high_and_low(numbers):
    nn = [int(s) for s in numbers.split(" ")]
    return "%i %i" % (max(nn),min(nn))
```

> 나와 비슷한 풀이이다.



```python
# Best Practices 2
def high_and_low(numbers):
  return " ".join(x(numbers.split(), key=int) for x in (max, min))
```

> for문을 이용해 함수를 전달 받을 수 있다는 것을 알게 됐다.

> `return " ".join(x(numbers.split(), key=int) for x in (max, min))` 보다는
>
> `return " ".join(function(numbers.split(), key=int) for function in (max, min))`가 더 좋다.
>
> 그냥 x 로만 써서 처음에 이해가 잘 안됐다.

> (질문)       sort(), sorted() 가 아닌 max,min에도 key사용이 가능한가요?



## 배운 점

>  for문을 통해 함수전달 받기, sorted() 에 대해 새로 알게 됐다.
>
>  key는 미흡.



## 반성할 점

> 반환형(type) 잘 생각하며 풀어야 한다. (틀린 이유를 찾는데 꽤 걸렸다.)



## Action Item

> 다양한 방법 생각해보기, type 주의해서 풀기

