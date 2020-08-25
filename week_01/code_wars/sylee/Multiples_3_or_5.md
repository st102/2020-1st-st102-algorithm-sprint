ECHO가 설정되어 있습니다.
# Multiples of 3 or 5 (week-01-02)

## 문제설명

> 자연수가 하나 주어지고, 주어진 수 이하의 범위에서 3또는 5의 배수들의 합을 구하기

## 나의 풀이 방법

 ```python
def solution(number):
    sum=0
    for i in range(number):
        if(i%3==0 or i%5==0):
            sum+=i
    return sum
 ```

> 처음작성 코드이다. 테스트케이스를 실행 했더니 통과했다. 하지만 너무 쉬웠다. 여기서 더 단축시켜보고 싶어 고민해보았다.
>
> - week-01-01에서 다른사람이 과제 한 것 중  `'C-like'하게 작성했다`는 말이 있었는데 그게 딱 이 상황 같았다.
> - 그 뒤에 첨부되어 있던 파이썬스럽게 짠 코드가 생각났다.
> - 그래서 적용시켜 보았다.

```python
def solution(number):
    return sum(i for i in range(number) if(i%3==0 or i%5==0))
```

>테스트 케이스가 성공하고 제출도 성공했다. 

+ 다른사람의 과제 PR을 보지 않았었다면 생각못했을거 같다. ㅋㅋ
  + 이렇게 성공하게 돼서 신기하다.



## 다른 사람의 풀이 방법

```python
# Best Practices 1
def solution(number):
    return sum(x for x in range(number) if x % 3 == 0 or x % 5 == 0)
```

> 내 코드와 99% 유사하다. if문에서 괄호 있는게 개인적으로 보기 더 편한거 같다.

```python
# Best Practices 2
def solution(number):
    sum = 0
    for i in range(number):
        if (i % 3) == 0 or (i % 5) == 0:
            sum += i
    return sum
```

 > 이건 내가 처음 작성했던거와 같다. c언어에서 문법만 python으로 바뀐거 같다. 정답이긴 하지만 python을 이용하는 메리트가 없다는 생각함.


## 배운 점

>  최소 1가지 이상의 배운점을 적어본다 - 사소한 것도 상관없음

	- python스럽게 생각하기 (우연히 전 과제에서 비슷한 케이스를 봐서 성공했던거 같다.ㅋㅋ)
	- generator expression

## 반성할 점

> 코드를 봤을 때 python스럽다! 라고 생각은 할 수 있는데 단번에 python스럽게 생각하긴 어려운거 같다.
> 이 외에 특별히 반성할 점은 없는거 같다. 지난 번 Action item을 적용할 뭔가 없었던 거 같다.

## Action Item

> 특이사항 없음.