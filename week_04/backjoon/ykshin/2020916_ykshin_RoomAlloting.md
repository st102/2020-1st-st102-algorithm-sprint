# {방 배정하기}

## 문제 설명
주어진 세수를 조합하면 특정 수를 만들 수 있는지 구하는 문제


## 나의 풀이 방법
dp를 이용해서 해당 수가 만들어질려면 해당 수 -a,-b,-c 가 만들 수 있어야한다.
```kotlin
 for (i in 1..n) {
            if (isOk(i - a) || isOk(i - b) || isOk(i - c)) {
                dp[i] = true
            }
        }
private fun isOk(i: Int): Boolean {
        return i > 0 && dp[i]
    }
```

## 다른 사람의 풀이 방법
완전 탐새으로 반복문 3개를 겹쳐서 해결하는 방법
시간복잡도 상으로 최악의 경우 n^3에 비해 dp를 이용하면 n으로 해결할 수 있다.

## 배운 점
- dp적인 생각!

## 반성할 점
- dp적인 생각좀 빠릿하게 하자..

## Action Item
- dp적인 사고를 하자