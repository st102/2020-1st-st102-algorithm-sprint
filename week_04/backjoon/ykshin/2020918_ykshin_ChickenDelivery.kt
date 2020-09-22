import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min
import java.lang.System.`in`
import java.util.*
import kotlin.math.abs


fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferReader.readLine())
    val N = stringTokenizer.nextToken().toInt()
    val M = stringTokenizer.nextToken().toInt()
    val town = Array<IntArray>(N) {
        stringTokenizer = StringTokenizer(bufferReader.readLine())
        IntArray(N) {
            stringTokenizer.nextToken().toInt()
        }
    }
    println(ChickenDelivery().solution(town, N, M))
}

class ChickenDelivery {
    lateinit var town: Array<IntArray>
    var answer = Int.MAX_VALUE
    fun solution(town: Array<IntArray>, N: Int, M: Int): Int {
        this.town = town
        var row = -1
        val chickenList = mutableListOf<Pair<Int, Int>>()
        for (row in 0 until N) {
            for (col in 0 until N) {
                if (town[row][col] == 2) {
                    chickenList.add(Pair(row, col))
                }
            }
        }
        comb(chickenList, BooleanArray(chickenList.size), 0, chickenList.size, M)
        return answer
    }

    fun comb(arr: List<Pair<Int, Int>>, visited: BooleanArray, depth: Int, n: Int, r: Int) {
        if (r == 0) {
            answer = min(answer, chickenDistanceCalc(arr.filterIndexed { index, _ ->
                visited[index]
            }))
            return
        }
        if (depth == n) {
            return
        }
        visited[depth] = true
        comb(arr, visited, depth + 1, n, r - 1)
        visited[depth] = false
        comb(arr, visited, depth + 1, n, r)
    }

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
}
