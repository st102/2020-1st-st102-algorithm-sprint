# {적록색약}

## 문제 설명
주어진 그림에서 정상인과 적록색약인이 있는 사람이 보았을 때 몇개의 색 구역으로 이루어져 있는지 구하는 문제


## 나의 풀이 방법
주어진 그림을 dfs로 방문하여 몇 개의 구역으로 이루어져 있는지 탐색한다.

```kotlin
private fun explore(paint: List<CharArray>) : Int {
        var count = 0
        for (r in 0 until N) {
            for (c in 0 until N) {
                if (paint[r][c] != ' ') {
                    count++
                    dfs(paint, r, c, paint[r][c])
                }
            }
        }
        return count
    }

    private fun dfs(paint: List<CharArray>, row: Int, col: Int, color: Char) {
        if (row !in 0 until N || col !in 0 until N) return
        if (paint[row][col] != color) return
        paint[row][col] = ' '
        dfs(paint, row - 1, col, color)
        dfs(paint, row + 1, col, color)
        dfs(paint, row, col - 1, color)
        dfs(paint, row, col + 1, color)
    }
```
적록색약이 있는 경우도 동일하게 방문하기 위해 그림에서 G를 R로 변경해서 인자로 넘겨준다.
```kotlin
explore(paint.map { it.replace("G", "R").toCharArray()})
```

## 다른 사람의 풀이 방법
dfs를 방문검사할 때 r||g 방식으로 검사한다.

## 배운 점
- 모듈화를 해서 동일하게 처리하도록 하자

## 반성할 점
- 코테에서는 시간 복잡도의 문제로 g를 r로 변경하는 것에서 시간이 추가로 걸릴 수 가 있다. 주의하자

## Action Item
- 모듈화하기!