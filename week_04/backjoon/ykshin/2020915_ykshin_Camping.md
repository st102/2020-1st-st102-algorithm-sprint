# {캠핑}

## 문제 설명
연속일수 P, 연속일 수 동안 머물수 있는 날 L, 휴가기간 V 가 주어질 때 최대 몇 일동안 머무를 수 있는가

## 나의 풀이 방법
나누기 연산과 나머지 연산을 이용해 간단히 해결했다.

```kotlin
 fun solution(L: Int, P: Int, V: Int): Int {
        return V / P * L + min(V % P, L)
    }
```

## 다른 사람의 풀이 방법
동일하다.

## 배운 점
- 수학적으로 점화식(?)을 세울 수 있을 것 같은지 먼저 고민해보자! 

## 반성할 점
- 생각을 하고 짜자!(짜다가 이건 아니다 싶어서 갈아엎고 고민을 해보니 간단히 구해짐 ㅎ..)

## Action Item
- 코딩하기전에 생각을 하자