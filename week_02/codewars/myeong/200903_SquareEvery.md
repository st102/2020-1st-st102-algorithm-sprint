# Square Every Digits

## 문제 설명

*   모든 숫자 각 자리마다 제곱한 값으로 나타내어라

## 나의 풀이 방법

```python
def square_digits(num):
    list=[]
    for sqnum in str(num):
        list.append(int(sqnum)**2)
    return int(''.join(str(i) for i in list))
```

*   for문으로 num을 str로 바꿔 숫자하나마다 제곱한 값을 list에 넣었다.
*   return으로 join을 사용하여 문제에서 원하는대로 나오게 하였으며 문자열은 답으로 인정되지 않아 int를 추가하였다.

## 다른 사람의 풀이 방법

* ### Best Practice

  ```python
    def square_digits(num):
        ret = ""
        for x in str(num):
            ret += str(int(x)**2)
        return int(ret)
  ```

  * for문을 통하여 합치는 것은 나와 비슷하지만 문자열을 합치는 방법으로 풀이를 하였다.

* ### Clever

  ```python
  def square_digits(num):
    return int(''.join(str(int(d)**2) for d in str(num)))
  ```

  *   for문으로 제곱한 값을 join으로 출력하였다.

## 배운 점

*   python에서 join을 알게되었으며 문자열을 합치는 방법에 대해서도 다시 한번 깨닫게 되었다.

## 반성할 점

*   문자열을 합치는 간단한 방법을 떠올리지는 못해 반성하고 싶다. 하지만 이를 통해 join을 알게되었으므로
    그나마 다행이라고 생각한다.

## Action Item

*   처음으로 Best Practice와 Clever 둘다 내 풀이랑 좀 비슷했다!

