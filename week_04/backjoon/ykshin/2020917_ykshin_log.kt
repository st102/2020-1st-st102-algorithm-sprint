import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Math.abs
import java.lang.Math.max
import java.lang.System.`in`
import java.util.*
fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferReader.readLine())
    val T = stringTokenizer.nextToken().toInt()
    for (case in 0 until T) {
        val N = StringTokenizer(bufferReader.readLine()).nextToken().toInt()
        stringTokenizer = StringTokenizer(bufferReader.readLine())
        println(Log().solution(N, IntArray(N) {
            stringTokenizer.nextToken().toInt()
        }))
    }
}

class Log {
    fun solution(size: Int, logList: IntArray): Int {
        logList.sort()
        val track = IntArray(logList.size)
        var max = Int.MIN_VALUE
        for (i in 0 until size) {
            if (i % 2 == 0) {
                track[i / 2 ] = logList[i]
            } else {
                track[size -1 - i / 2 ] = logList[i]
            }
        }
        for (i in 0 until track.size - 1) {
            max = max(abs(track[i] - track[i + 1]), max)
        }
        max = max(abs(track.first() - track.last()), max)
        return max
    }
}
