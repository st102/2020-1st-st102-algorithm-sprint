# Dismvowel Trolls

## 문제 설명

*  주어진 배열에서 non-integer를 제외한 integer 배열을 만들어라.

## 나의 풀이 방법

### 문제 풀이 코드
```python
def filter_list(l):
    list_of_return = []
    for check_integer in l :
        if isinstance(check_integer , int):
            list_of_return.append(check_integer)
    
    return list_of_return
```
*  for문을 통해 list의 각각의 원소에 접근하여 isinstance 함수를 이용하여 integer인지 아닌지 판단하여 list를 만들었다,

### 테스트 코드
```python
# test_code_mixed_integers_and_non_integers
test.assert_equals(filter_list([1,2,'a','b']),[1,2])
test.assert_equals(filter_list([1,'a','b',0,15]),[1,0,15])
test.assert_equals(filter_list([1,2,'aasf','1','123',123]),[1,2,123])

# test_code_only_integers
test.assert_equals(filter_list([1,2,123]),[1,2,123])
test.assert_equals(filter_list([901]),[901])
test.assert_equals(filter_list([5,1,2,4,6,7]),[5,1,2,4,6,7])

# test_code_only_non_integers
test.assert_equals(filter_list(['a','b','dd']),[])
test.assert_equals(filter_list(['c']),[])

# test_code_empty_list
test.assert_equals(filter_list([]),[])
```

*  integer와 non-integer로 나올수 있는 조합들에 대해서 테스트 코드를 작성하였다.
*  파이썬으로 테스트 코드를 작성한 적은 첨이라 한번에 묶지 못했다 ㅠㅠ

## 다른 사람의 풀이 방법

### Best Practice

```python
def filter_list(l):
  return [i for i in l if not isinstance(i, str)]
```

### Clever

```python
def filter_list(l):
  return [i for i in l if not isinstance(i, str)]
```

*  나랑 같은 알고리즘인거 같지만 배열에 저장하는 방식이 나는 append함수를 이용하였고 여기서 바로 대입을 한거 같다.
*  파이썬은 익숙하지 않아 이런 문법이 너무 신기하다.

## Action Item

*  아직은 c++로 문제를 풀고 있지만 나중에는 한번 파이썬을 공부하여 파이썬으로도 문제를 풀어보고 싶다