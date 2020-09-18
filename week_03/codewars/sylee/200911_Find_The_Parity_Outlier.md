# Find The Parity Outlier

## 문제설명

> 정수리스트를 받아 다른 parity를 가진 정수를 출력

## 나의 풀이 방법

 ```python
def find_outlier(integers):
    even = 0
    odd = 0

    for element in integers:
        if element % 2:
            odd += 1
        else:
            even += 1
    if even > 1:
        return [x for x in integers if x % 2][0]
    else:
        return [x for x in integers if x % 2 == 0][0]
 ```

> 처음 풀이이다. 



```python
def find_outlier(integers):
    list_even = [elem for elem in integers if elem % 2 == 0]
    list_odd = [elem for elem in integers if elem % 2]

    return list_even[0] if len(list_even) < len(list_odd) else list_odd[0]
```

> 리팩토링후 코드이다.
>
> 두 리스트 중 하나의 길이는 무조건 1이고 다른 리스트의 길이는 2 이상이다. (주어진 리스트의 길이는 최소 3)
>
> 이를 이용하여 코드를 짰다.



```python
class TestFindOutlier(unittest.TestCase):
    def test_when_given_only_odd(self):
        self.assertEqual(find_outlier([2, 4, 6, 8, 10, 3]), 3)

    def test_when_given_only_even(self):
        self.assertEqual(find_outlier([160, 3, 1719, 19, 11, 13, 21]), 160)

    def test_when_given_only_odd_negative(self):
        self.assertEqual(find_outlier([2, 4, 6, 8, 10, -3]), -3)

    def test_when_given_only_even_negative(self):
        self.assertEqual(find_outlier([-160, 3, 1719, 19, 11, 13, 21]), -160)
```

> 홀수와 짝수가 각각 1개인 경우와
>
> 그 홀수와 짝수가 각각 음수인 경우까지 테스트 했다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def find_outlier(int):
    odds = [x for x in int if x%2!=0]
    evens= [x for x in int if x%2==0]
    return odds[0] if len(odds)<len(evens) else evens[0]
```

> 나와 거의 같다. odds의 list comprehension에서 if조건을 True, False로 검사하는데 
>
> 나는 bool값으로 검사했다.



```python
# Best Practices 2
def find_outlier(integers):
    parity = [n % 2 for n in integers]
    return integers[parity.index(1)] if sum(parity) == 1 else integers[parity.index(0)]
```

> `parity`리스트는 0이 유일하거나 1이 유일하게 된다.
>
> `sum(parity) == 1`이면 1이 유일 하므로 `integers[parity.index(1)]`를 반환하였다.
>
> 좋은 것 같다.



## 배운 점

>  리스트를 따로 생성하지않고, 필요한 부분만을 뽑는 방법도 생각해보자.



## 반성할 점

> 특별히 없었다.



## Action Item

> 테스트코드,TDD