# Find the missing term in an Arithmetic Progression

## 문제 설명

어떤 수열이 있을 때, 그 수열에서 빠진 숫자 1개를 골라낸다.

Ex)

 * ```
   find_missing([1, 3, 5, 9, 11]) == 7
   ```

   

## 나의 풀이 방법

```python
import unittest


def find_missing(sequence):
    def get_last_by_diff(diff, last_value):
        if diff < 0:
            last_value -= 1
        else:
            last_value += 1
        return last_value

    first, last = sequence[0], sequence[-1]
    diff = (last - first) // len(sequence)

    last = get_last_by_diff(diff, last)
    return sum(range(first, last, diff)) - sum(sequence)

```

* 문제 조건 중, 변하지 않는 것으로 제한이 된 것은 첫번째 값과 맨 마지막 값이였다.
* 그 값들을 이용해서 `diff` 를 구하고, 원래 `수열의 합` - `주어진 수열의 합` 을 하면, 빠진 숫자 1개가 나올 것이라고 생각하고 문제를 풀었다.



## 다른 사람의 풀이 방법

### 가장 깔끔하다고 생각하는 풀이

```python
def find_missing(sequence):
    s = set(sequence)
    m1, m2 = min(s), max(s)
    for i in range(m1, m2 + 1, (m2 - m1) // len(s)):
        if i not in s:
            return i
```

* `diff` 를 구하여서, 완성된 수열을 구하고, 멤버쉽 체크로 없는 것을 return 해준다.
* 정민님 풀이 법인데, 매우 깔끔하고 군더더기 없는 코드라고 생각한다.

### 그외 다른 풀이 1

```python
def find_missing(sequence):
    interval = (sequence[-1] - sequence[0])/len(sequence)
    for previous, item in enumerate(sequence[1:]):
        if item - sequence[previous] != interval:
            return item - interval
```

* 역시 이 문제의 포인트는 첫값과 마지막 값으로 diff를 구하는 것이다.
* 이 문제에서는 바로 인접한 값들을 일일이 비교하여서, interval값과 다르면 바로 리턴하였다.
* 이 코드 역시 매우 깔끔하고 문제를 푸는데 최적화된 풀이라고 생각한다.

### 그외 다른 풀이 2

```python
def find_missing(sequence):
    t = sequence
    return (t[0] + t[-1]) * (len(t) + 1) / 2 - sum(t)
```

* 수열의 전체합을 구하는 식을 활용하였다.

  * ```
    (first + last) * len(n) / 2
    ```

* 빠지지 않았다고 가정하고 `(len(t) + 1)` 로 계산하고, `sum(t)` 를 빼면, 매우 간단하게 답을 구할 수 있다.



## 배운 점

* 기존에 수열에서 `diff` 구하는 법을 특정 수열 내 요소 끼리의 차 로 구했었는데, 첫값과 마지막 값을 활용하는 방법도 알게 되었다.

  * ```python
    # 수열의 diff 구하기
    diff = (last - first) // len(sequence)
    ```

* 수열 전체의 합 구하기

  * ```python
    # 수열 전체의 합
    all_sum = (first + last) * len(n) / 2
    ```

    

## 반성할 점

* 수열과 관련된 문제를 이전에도 여러번 푼 것 같은데, 이전에 풀었던 방식에 대한 어떤 패턴을 찾지 못한채 이 문제를 풀 때 처음부터 다시 풀었다.
* 그로인해서, 문제 푸는 시간이 늘어났고 diff를 구하면 쉽게 풀 수 있는 문제였는데 diff를 구하는 식 자체 부터 제대로 구하지 못하여서 시간이 오래 걸렸다.
* 위와 같은 패턴들을 미리 알았다면 문제를 더쉽고 빠르게 풀었을 수 있었을 것 같다.



## Action Item

* 안키에 위의 배운 점들을 기록하고, 주기적으로 확인한다.
* 다음에 수열관련 문제들이 나왔을 때 위에서 배운 것들을 활용가능할지 최초로 염두해보고 문제를 풀어본다.
