# {통나무}

## 문제 설명
정수형 배열이 주어질 때 순서를 바꿔서 양옆에 값과 차가 가장 큰 값을 난이도라고 할때, 난이도를 가장 낮게 하는 순열 찾기


## 나의 풀이 방법
가장 작은값과 가장 큰값이 떨어져야하고, 각 수의 양 옆에는 본인과 가장 차이가 적은 수가 와야한다.
1. 오름차순으로 정렬
2. 0123456 이 있다면, 0246 135를 나누고 홀수 배열을 뒤집어 붙힌다. 
3. 0246531이 정렬된 수열
4. 정렬된 수열을 순회하며 차의 최대를 구한다.
```kotlin
        logList.sort()
                val track = IntArray(logList.size)
                var max = Int.MIN_VALUE
                for (i in 0 until size) {
                    if (i % 2 == 0) {
                        track[i / 2 ] = logList[i]
                    } else {
                        track[size -1 - i / 2 ] = logList[i]
                    }
                }
                for (i in 0 until track.size - 1) {
                    max = max(abs(track[i] - track[i + 1]), max)
                }
                max = max(abs(track.first() - track.last()), max)
```

## 다른 사람의 풀이 방법
나와 똑같은 접근.. 단 3줄.. 벽느낀다...
코틀린은 이렇게 써야하는데.. 지금까지 잘못써온것 같다..
```kotlin
fun main(args: Array<String>) {
  repeat(readLine()!!.toInt()) {
    val N = readLine()!!.toInt()
    val L = readLine()!!.split(" ").map{ it.toInt() }.toList().sorted()
    println((0 until N-2).map{ L[it+2] - L[it] }.max()!!)
  }
}
```
## 배운 점
- kotlin의 진짜 사용방법..

## 반성할 점
- kotlin을 잘 활용하자

## Action Item
- kotlin 공부 다시해... ㅜㅠㅠㅠㅠㅠ