# {유기농 배추}

## 문제 설명
밭에서 배추를 지키는 벨러는 인접한 배추를 모두 지킨다. 배추끼리 인접해 있어도 지킬 수 있다.
밭을 지키는 최소한의 벌레의 수를 구하는 문제

## 나의 풀이 방법
배열 전체를 탐색하면서 배추가 발견되면 해당 배추를 기준으로 dfs로 상하좌우를 보며 배추인 곳은 방문 표시를 한다.

```kotlin
    fun dfs(row: Int, col: Int, farm: Array<IntArray>) {
        if (!check(row, col, farm)) return
        farm[row][col] = VISITED
        dfs(row + 1, col, farm)
        dfs(row - 1, col, farm)
        dfs(row, col + 1, farm)
        dfs(row, col - 1, farm)
    }
    
    fun check(row: Int, col: Int, farm: Array<IntArray>): Boolean {
        return row in 0 until ROW && col in 0 until COL && farm[row][col] == BACHU
    }
```

## 다른 사람의 풀이 방법
dfs로 간단히 풀리는 문제라 다들 dfs로 접근하여 풀었다.

## 배운 점
- 조건문을 하나의 함수로 묶어서 가독성을 높이는 점

## 반성할 점
- 자정이 넘었다 ㅎ.. 일찍일찍 풀자

## Action Item
- 조건문을 하나의 함수로 묶어서 개발하자.