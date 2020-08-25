# Multiples of 3 or 5 

## 문제 설명

*   주어진 숫자 미만의 수 중에 3 or 5 의 배수 값들의 합을 구한다

## 나의 풀이 방법

```python
import unittest


def solution(number):

    def is_multiples_of_3_or_5(element):
        return element % 3 == 0 or element % 5 == 0

    return sum(element for element in range(3, number) if is_multiples_of_3_or_5(element))
    
    
class TestSolution(unittest.TestCase):
    def test_solution_should_return_10_with_number_is_10(self):
        self.assertEqual(solution(10), 23)

    def test_solution_should_return_0_with_number_is_0(self):
        self.assertEqual(solution(0), 0)

    def test_solution_should_return_1_with_number_is_0(self):
        self.assertEqual(solution(1), 0)

    def test_solution_should_return_2_with_number_is_0(self):
        self.assertEqual(solution(2), 0)
```

*   3 or 5의 배수 인지를 체크하는 inner function을 만든 후, generator comprehension 으로 표현한 이후에 sum()을 이용해서 리턴한다.
*   range 의 범위는 3부터 시작하였는데, 어차피 0, 1, 2 는 3의 배수가 아니기 때문에 그냥 제외하였고, 이에 대한 테스트를 추가해주었다.

## 다른 사람의 풀이 방법

### Best Practice

```python
def solution(number):
    return sum(x for x in range(number) if x % 3 == 0 or x % 5 == 0)
```

*   내가 푼 방법과 사실상 거의 동일한 방법을 사용하였다.
*   내가 inner function을 따로 만들어준 이유는 좀 더 읽기 쉽게 하기 위해서 뺴준 것인데, 사실 이 코드에서는 위 처럼 해도 가독성에는 크게 문제가 없어 보인다

###Clever

```python
def solution(number):
    a3 = (number-1)/3
    a5 = (number-1)/5
    a15 = (number-1)/15
    result = (a3*(a3+1)/2)*3 + (a5*(a5+1)/2)*5 - (a15*(a15+1)/2)*15
    return result
```

*   Clever 문제는 위 문제이다.
*   일단 위 코드의 문제 점은 변수명을 대충 지은 것이다.(a3, a5, a15) 현업에서는 절대 저렇게 변수명을 지어서는 안된다
*   그리고 result 변수는 쓸데 없이 선언한 것으로 보인다 그냥 inline 해서 바로 return 해도 크게 문제 없어 보인다
*   풀이 자체가 신박한 방법을 썼는데, 개인적으로 이런 코드는 가독성도 좋지않고 디버깅도 힘들기 때문에 좋아하지 않는다
*   Clever 투표를 많이 받긴 했지만 좋은 코드라고는 볼 수 없을 거 것 같다

## 배운 점

*   Clever 같은 풀이는 성능적으로 어떤 이점이 있을지 모르겠지만, 지양해야하는 코드 스타일 이다

## 반성할 점

*   이번 문제를 통해 반성할 점은 아니고,  이 문제는 두번째 푸는 것인데, 예전에 내가 풀었던 풀이를 보니 매우 비효율적으로 푼 것을 볼 수 있었다.

```python
# 예전 답(약 10개월 전)

def solution(number):
    natural_number = list(range(1, number))
    temp_dict = dict.fromkeys(natural_number,0)
    for ele in natural_number:
        if ele % 3 == 0 and (temp_dict.get(ele) is 0):
            temp_dict[ele] += 1
            
        if ele % 5 == 0 and (temp_dict.get(ele) is 0):
            temp_dict[ele] += 1    
    return sum( key for key in temp_dict if temp_dict[key] is not 0)
```

*   변수명은 나름 신경쓰려고 한 흔적이 보이는데, 전체적으로 코드에 중복과 쓸 데 없는 코드들이 많다.
*   굳이 dict를 쓸 필요도 없어 보이고, dict의 get으로 0 인지 체크하는 부분도 굳이 필요 없어 보인다
*   가독성이 매우 안좋다

## Action Item

*   내가 예전에 짰던 코드들을 리팩토링 해보자.