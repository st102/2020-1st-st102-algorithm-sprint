#### Find the odd int

## 문제설명

한 정수 리스트가 주어지고, 리스트중에서 개수가 홀수개인 요소를 출력한다.

(단, 개수가 홀수개인 요소는 단 하나이다.)

## 나의 풀이 방법

 ```python
def find_it(seq):
    list_of_Odd_element = []
    for element in seq:
        if element in list_of_Odd_element:
            list_of_Odd_element.remove(element)
        else:
            list_of_Odd_element.append(element)
    return list_of_Odd_element[0]
 ```

> 처음작성 코드이다. 

1. 개수가 홀수개인 요소를 저장할 리스트 `list_of_Odd_element` 를 선언한다.

2. for문 을 통해 리스트 `seq`의 요소들을 차례대로 비교한다.

3. 해당 `element`가 리스트 `list_of_Odd_element`에 없으면 추가, 있으면 삭제 한다.

   ( 개수가 홀수개라면 `list_of_Odd_element`에 남게된다.)

> 정상적으로 잘 작동했다. 이 코드를 짜면서 리스트에서 특정 요소의 개수를 반환해주는 함수가 있으면 좋겠다고 생각했다.



```python
def find_it(seq):
    return [element for element in seq if seq.count(element) % 2 != 0][0]
```

>인터넷에 검색해보니 `count()`라는 Method 를 발견했다.

>  list의 index를 이용하여 풀었다. (홀수개인 요소는 하나이므로 index는 0이다. )




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def find_it(seq):
    return [x for x in seq if seq.count(x) % 2][0]
```

> 내가 짠 코드와 비슷하다. if문의 표현식의 불 값을 그대로 사용하였다는 점이 다르다.



```python
# Best Practices 2
def find_it(seq):
    return next(x for x in set(seq) if seq.count(x) % 2)
```

 > set()이라는 처음 보는 메소드가 있었다.  중복을 제거하고 순서를 보정해준다. (오름차순)
 >
 > set()을 사용하게 되면 불필요한 연산을 줄일 수 있어서 좋을 거 같다.



```python
# Clever	
import operator

def find_it(xs):
    return reduce(operator.xor, xs)
```

> reduce() 메소드와 xor 연산자를 사용하여 함수를 만들었다.

> 이게 어떻게 작동되는지 잘 몰랐는데, 댓글 중 설명해 놓은 사람이 있어서 참고했다.

> ` xor is communicative so you don't have to worry about the order of the values. A list like [1, 2, 3, 1, 2, 3, 4] can be thought of as [1, 1, 2, 2, 3, 3, 4]` 

> 이렇게 되면 결과적으로 홀수개인 요소 하나가 남게 된다.

## 배운 점

>  count(), set(), reduce(), operator(xor)에 대해 알게 되었다.

	

## 반성할 점

> 내가 모르는 함수, method들이 많다. 자주 쓰이고 유용한 것들은 좀 배워놔야 겠다.



## Action Item

> 배운 사항들을 이용하고, 아직 모르는 기능들이 많기 때문에 풀다가 있으면 좋겠다라고 생각하는 기능들은 검색해서 알아보도록 해야겠다.