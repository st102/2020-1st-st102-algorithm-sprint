# Vowel Count

## 문제 설명

*   주어진 string 내의 모음 개수를 계산한다

## 나의 풀이 방법

```python
import unittest


def get_count(input_str):
    return sum(1 for char in input_str if char in 'aeiou')


class TestGetCount(unittest.TestCase):
    def test_get_count_should_return_0_with_empty_string(self):
        input_str = ''
        actual = get_count(input_str)
        self.assertEqual(actual, 0)

    def test_get_count_should_return_0_with_no_vowel(self):
        input_str = 'qwrtp'
        actual = get_count(input_str)
        self.assertEqual(actual, 0)

    def test_get_count_should_return_5_with_only_vowel(self):
        input_str = 'aeiou'
        actual = get_count(input_str)
        self.assertEqual(actual, 5)

```

*   Generator comprehension을 사용하여서 간략하게 풀이하였다.
*   테스트는 empty_string 일 때, vowel 이 없을 때, vowel 만 이루어졌을 때로 나누었다.

## 다른 사람의 풀이 방법

### Best Practice

```python
def getCount(inputStr):
    return sum(1 for let in inputStr if let in "aeiouAEIOU")
```

*   내가 쓴 답과 거의 비슷한데, 이 경우에는 string에 대문자가 포함되었을 경우에도 커버를 해주었다
*   내 답 보다는 이 답이 좀 더 베스트 프랙티스 이다

###Clever

```python
def getCount(s):
    return sum(c in 'aeiou' for c in s)
```

*   내 생각에 이 답이 좀더 베스트 프랙티스에 가깝다고 생각한다.
*   필터링 해서 1을 더할 필요없이, `in` 을 이용하여서 True,False로 이루어진 generator expression 을 만든 후, `sum` 을 하는 방식이 좀 더 우아한 방식 처럼 보인다 :thumbsup:

## 배운 점

*   generator comprehension에서 filter를 이용하지 않고, `in` 을 이용해서 `True`의 개수로 vowel count 쓰는 법을 배웠다

## 반성할 점

*   이번 문제를 통해 반성할 점은 아니고,  이 문제는 두번째 푸는 것인데, 예전에 내가 풀었던 풀이를 보니 매우 비효율적으로 푼 것을 볼 수 있었다.

```python
# 예전 답(약 10개월 전)

def getCount(inputStr):
    vowels  = {'a', 'e', 'i', 'o', 'u'}
    
    if len(inputStr) == 0:
        return 0
    
    temp_dict = {}
    for ele in inputStr:
        if ele in vowels:
            if temp_dict.get(ele):
                temp_dict[ele] += 1
                
            else:
                temp_dict[ele] = 1
                
    return sum(temp_dict.values())
```

*   일단 메소드 명 부터 카멜 케이스 로 적혀있는 것 부터 문제
*   나름 멤버쉽 체크를 위해서 vowels set 을 만들긴 했으나, 굳이 set 만들지 않아도 될 것 같다(개수가 적어서)
*   temp_dict를 굳이 만들어서 연산할 필요가 없음
*   Temp_dict.get(ele) 를 굳이 써서 체크할 필요 없음

위의 사항처럼 10개월 전에는 매우 비효율적으로 푼 것을 알 수 있었고, 앞으로도 저렇게 풀지 않도록 주의해야곘다

## Action Item

*   쉬운 문제일 수록, 좀 더 고민해서, 더 파이써닉 하게 풀 수 있는 방법으로 리팩토링 해서 풀자