import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

const val BACHU = 1
const val VISITED = 2
var ROW = 0
var COL = 0

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    val t = bufferedReader.readLine().toInt()
    for (case in 0 until t) {
        var stringTokenizer = StringTokenizer(bufferedReader.readLine())
        ROW = stringTokenizer.nextToken().toInt()
        COL = stringTokenizer.nextToken().toInt()
        val farm = Array(ROW) { IntArray(COL) }
        val k = stringTokenizer.nextToken().toInt()
        for (i in 0 until k) {
            stringTokenizer = StringTokenizer(bufferedReader.readLine())
            farm[stringTokenizer.nextToken().toInt()][stringTokenizer.nextToken().toInt()] = 1
        }

        var count = 0
        for (row in 0 until ROW) {
            for (col in 0 until COL) {
                if(farm[row][col]==BACHU){
                    count++
                    dfs(row, col, farm)
                }
            }
        }
        println(count)
    }
}

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
