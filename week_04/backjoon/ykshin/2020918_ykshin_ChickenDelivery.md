# {치킨 배달}

## 문제 설명
주어진 2차원 정수형 배열에서, 1은 집 ,2는 치킨집을 의미한다.
이떄 어떤 치킨집을 남겨야 집과 치킨집의 거리가 최소가 되는가.


## 나의 풀이 방법
1. 치킨집의 리스트를 가져온다.
2. 해당 리스트에서 M개를 뽑는 조합을 구한다.
3. 조합이 만들어 질떄마다 치킨 거리를 갱신한다.
```kotlin
        fun chickenDistanceCalc(chickenList: List<Pair<Int, Int>>): Int {
                var sum = 0
                town.forEachIndexed { row, rows ->
                    rows.forEachIndexed { col, building ->
                        if (building == 1) {
                            sum += calc(row, col, chickenList)
                        }
                    }
                }
                return sum
            }
        
            private fun calc(row: Int, col: Int, chickenList: List<Pair<Int, Int>>): Int {
                var minDistance = Int.MAX_VALUE
                chickenList.forEach {
                    minDistance = min(abs(it.first - row) + abs(it.second - col), minDistance)
                }
                return minDistance
            }
```

## 다른 사람의 풀이 방법
백트랙킹을 이용해 어떤 치킨집을 선택하냐에 따라서 값을 갱신한다. 갱신하는 중에 min을 초과하면 돌아가는 방식으로 실행시간을 줄인다. 

## 배운 점
- 입력 범위 보고 완전탐색으로 해도 되는지 계산하는 법

## 반성할 점
- 같은 완전탐색이어도 백트랙킹을 이용하면 빠르다!

## Action Item
- 완전탐색이다 싶으면 후딱 짜자