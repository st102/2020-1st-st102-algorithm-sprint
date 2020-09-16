import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`

fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    val N = bufferReader.readLine().toInt()
    val paint = Array(N) {
        bufferReader.readLine()
    }
    println(RedGreenBlindness().solution(paint))
}

class RedGreenBlindness {
    var N = 0
    fun solution(paint: Array<String>): String {
        N = paint.size
        return "${explore(paint.map { it.toCharArray() })} ${explore(paint.map { it.replace("G", "R").toCharArray() })}"
    }

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
}