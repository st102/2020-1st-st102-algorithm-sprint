# {파티}

## 문제 설명
주어진 그래프에서 각지점에서 출발하여 특정 지점을 경유하고 다시 돌아오는 값의 최대값을 찾아라


## 나의 풀이 방법
플로이드와샬을 이용해 각 정점의 최단거리를 구하고 특정 지점과의 왕복거리를 구하여 출력한다.

```kotlin
 private fun floydWarshall(graph: Array<IntArray>) {
        val N = graph.size
        for (mid in 0 until N) {
            for (start in 0 until N) {
                for (end in 0 until N) {
                    val newDistance = graph[start][mid] + graph[mid][end]
                    if (newDistance < graph[start][end]) {
                        graph[start][end] = newDistance
                    }
                }
            }
        }
    }
```
```kotlin
var max = Int.MIN_VALUE
        for (i in 0 until N) {
            val distance= graph[i][X - 1] + graph[X - 1][i]
            if(max<distance){
                max = distance
            }
        }
        return max
```

## 다른 사람의 풀이 방법
다익스트라를 이용해 순방향과 역방향의 거리를 구한다.
플로이드와샬이 n^3인것에 비해, 해당 방법을 이용하면 2n^2의 시간복잡도로 해결가능하다.

## 배운 점
- 다익스트라를 양방향으로 하여 계산하여 양방향 그래프를 해결하는 방법

## 반성할 점
- 알고있는 유형이라해서 바로 하지말고, 한번더 고민!

## Action Item
- 짜기전에 생각좀!!!