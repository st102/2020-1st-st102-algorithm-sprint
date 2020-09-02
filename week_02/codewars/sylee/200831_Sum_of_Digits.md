# Create Phone Number

## 문제설명

> 10개의 정수를 받아 (xxx) xxx-xxxx의 형태로 출력하기

## 나의 풀이 방법

 ```python
def create_phone_number(n):
    return "({}{}{}) {}{}{}-{}{}{}{}".format(*n[:10])
 ```

> 어제 배웠던 *args를 이용해 풀었다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def create_phone_number(n):
    return "({}{}{}) {}{}{}-{}{}{}{}".format(*n)
```

> 내 풀이와 거의 비슷하다.



```python
def create_phone_number(n):
    n = "".join([str(x) for x in n] )
    return("(" + str(n[0:3]) + ")" + " " + str(n[3:6]) + "-" + str(n[6:]))
```

> 읽기 힘든 코드인 것 같다. 문자열을 연결할 때 되도록 `+` 사용을 지양 해야겠다.



## 배운 점

>  *args와 더불어 **kwargs도 잘 알아보자



## 반성할 점

> 특별히 없다고 생각한다.

## Action Item

> 숏코딩도 좋지만 가독성도 챙겨가면 좋을 것 같다.