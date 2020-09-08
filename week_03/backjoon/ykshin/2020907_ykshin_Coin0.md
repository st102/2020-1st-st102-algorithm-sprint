# {동전0}

## 문제 설명
주어진 금액을 주어진 동전의 최소개수로 만드는 문제

## 나의 풀이 방법
가장 큰 동전부터 나누기 연산을 통해 몇개까지 가능한지를 구하고 이를 합에서 차감하고 이를 반복한다.

```kotlin
      var sum = k
      var count = 0
      for(i in coins.size-1 downTo 0){
          val no = sum / coins[i]
          count+=no
          sum-=no * coins[i]
      }
```

## 다른 사람의 풀이 방법
내가 5달전에 풀었던 방법이다...
나누기 연산이 아니라 하나씩 빼가면서 언산을 진행한다.

```kotlin
fun greedy():Int {
    var result=0
    while(k!=0){
        if(k-coins.last()>=0){
            k-=coins.last()
            result++
        } else{
            coins.removeAt(coins.size-1)
        }
    }
    return result
}
```
실행시간이 172ms 에서 80ms로 감소했다. 발전했다 ㅎ

## 배운 점
- 발전해가고있다!

## 반성할 점
- 더 강해지자..

## Action Item
- 아자아자