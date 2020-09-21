# {퇴사}

## 문제 설명
각 상담별로 소요 시간과 금액이 주어질 떄, 어떤 상담들을 해야 주어진 기간 동안 금액을 가장 크게 할 수 있는가


## 나의 풀이 방법
dp를 이용하여, 마지막 날 부터 그 날 부터 마지막 날까지 벌 수 있는 최대 금액을 저장한다.
7일이라 가정할 떄, 4일 상담이 이틀이 걸리면, max(4일 상담 금액 + dp[6일],dp[5일])을 dp를 갱신해 나아간다. 
```kotlin
        val dp = IntArray(n)
        dp[n-1] = if(consultList[n-1].first==1) consultList[n-1].second else 0
        for (day in n - 2 downTo 0) {
            val consult = consultList[day]
            val nextDay = consult.first + day
            if (nextDay <= n) {
                dp[day] = max(consult.second + if(nextDay==n) 0 else dp[nextDay], dp[day+1])
            }else{
                dp[day]=dp[day+1]
            }
        }
        return dp[0]
```

## 다른 사람의 풀이 방법
dfs를 이용해 완전탐색방식
해당 dfs를 이용하면 시간 복잡도가 n*n! 까지 늘어 날 수 도 있다. dp를 이용하면 n으로 해결 가능!

## 배운 점
- dp를 문제에 맞게 거꾸로도 적용해보자

## 반성할 점
- dp적인 생각좀 빠릿하게 하자..

## Action Item
- dp적인 사고를 하자