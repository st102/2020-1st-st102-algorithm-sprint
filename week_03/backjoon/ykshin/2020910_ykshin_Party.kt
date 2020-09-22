import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferReader.readLine())
    val N = stringTokenizer.nextToken().toInt()
    val M = stringTokenizer.nextToken().toInt()
    val X = stringTokenizer.nextToken().toInt()
    val lineList = Array<IntArray>(M) {
        stringTokenizer = StringTokenizer(bufferReader.readLine())
        IntArray(3) {
            stringTokenizer.nextToken().toInt()
        }
    }
    println(Party().solution(N, X, lineList))
}

class Party {
    companion object {
        const val MAX = 1000000
    }

    fun solution(N: Int, X: Int, lineList: Array<IntArray>): Int {
        val graph = Array<IntArray>(N) { start ->
            IntArray(N) { end ->
                if (start == end) {
                    0
                } else {
                    MAX
                }
            }
        }
        lineList.forEach {
            val start = it[0] - 1
            val end = it[1] - 1
            val distance = it[2]
            graph[start][end] = min(distance,graph[start][end])
        }
        floydWarshall(graph)
        var max = Int.MIN_VALUE
        for (i in 0 until N) {
            val distance= graph[i][X - 1] + graph[X - 1][i]
            if(max<distance){
                max = distance
            }
        }
        return max
    }

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
}