import java.lang.System.`in`
import java.util.*

fun main() {
    val scanner = Scanner(`in`)
    val n = scanner.nextInt()
    val m = scanner.nextInt()
    val array = Array(n) { Array(m) { 0 } }
    for (i in 0 until n) {
        for (j in 0 until m) {
            array[i][j] = scanner.nextInt()
        }
    }
    println(buildWall(n, m, array))
}

fun buildWall(n: Int, m: Int, array: Array<Array<Int>>): Int {
    var max = Int.MIN_VALUE
    for (i in 0 until n * m - 2) {
        if (array[i / m][i % m] != 0) continue
        array[i / m][i % m] = 1
        for (j in i until n * m - 1) {
            if (array[j / m][j % m] != 0) continue
            array[j / m][j % m] = 1
            for (k in j until n * m) {
                if (array[k / m][k % m] != 0) continue
                array[k / m][k % m] = 1
                val new = check(deepCopy(array, n, m))
                if (new > max) max = new
                array[k / m][k % m] = 0
            }
            array[j / m][j % m] = 0
        }
        array[i / m][i % m] = 0
    }
    return max
}


fun check(array: Array<Array<Int>>): Int {
    for (row in array.indices) {
        for (col in array[row].indices) {
            if (array[row][col] == 2) {
                recursiveSpread(row, col, array)
            }
        }
    }
    return array.sumBy { it.count { it == 0 } }
}

fun recursiveSpread(row: Int, col: Int, array: Array<Array<Int>>) {
    if (col > 0 && array[row][col - 1] == 0) {
        array[row][col - 1] = 2
        recursiveSpread(row, col - 1, array)
    }
    if (col < array[row].size - 1 && array[row][col + 1] == 0) {
        array[row][col + 1] = 2
        recursiveSpread(row, col + 1, array)
    }
    if (row > 0 && array[row - 1][col] == 0) {
        array[row - 1][col] = 2
        recursiveSpread(row - 1, col, array)
    }
    if (row < array.size - 1 && array[row + 1][col] == 0) {
        array[row + 1][col] = 2
        recursiveSpread(row + 1, col, array)
    }
}

fun deepCopy(array: Array<Array<Int>>, n: Int, m: Int): Array<Array<Int>> {
    return Array(n) { i -> Array<Int>(m) { j -> array[i][j] } }
}