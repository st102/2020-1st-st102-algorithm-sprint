import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

var LIST_SIZE = 0
lateinit var apartmentLists: Array<IntArray>
fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    LIST_SIZE = bufferedReader.readLine().toInt()
    apartmentLists = Array(LIST_SIZE) {
        val str = bufferedReader.readLine()
        IntArray(LIST_SIZE) {
            str[it].toString().toInt()
        }
    }

    val countList = mutableListOf<Int>()
    apartmentLists.forEachIndexed { row, apartmentList ->
        apartmentList.forEachIndexed { col, apartment ->
            if (apartment == 1) {
                countList.add(dfs(apartmentLists, row, col))
            }
        }
    }
    println(countList.size)
    countList.sorted().forEach { println(it) }
}

fun dfs(apartmentLists: Array<IntArray>, row: Int, col: Int): Int {
    if (!check(row, col)) return 0
    if (apartmentLists[row][col] == 0) return 0
    apartmentLists[row][col] = 0
    return dfs(apartmentLists, row + 1, col) +
            dfs(apartmentLists, row - 1, col) +
            dfs(apartmentLists, row, col + 1) +
            dfs(apartmentLists, row, col - 1) + 1
}

fun check(row: Int, col: Int): Boolean {
    return row in 0 until LIST_SIZE && col in 0 until LIST_SIZE
}


