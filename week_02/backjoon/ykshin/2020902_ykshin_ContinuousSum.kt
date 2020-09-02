import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    val n = bufferedReader.readLine().toInt()
    val stringTokenizer = StringTokenizer(bufferedReader.readLine())
    val sequence = Array(n) { stringTokenizer.nextToken().toInt() }
    var max = sequence[0]
    for (i in 1 until n) {
        if (sequence[i - 1] > 0 && sequence[i] + sequence[i - 1] > 0) {
            sequence[i] += sequence[i - 1]
        }
        if (max < sequence[i]) {
            max = sequence[i]
        }
    }

    println(max)
}
