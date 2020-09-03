import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    val n = bufferedReader.readLine().toInt()
    val stringTokenizer = StringTokenizer(bufferedReader.readLine())
    val sequence = Array(n) { stringTokenizer.nextToken().toInt() }
    var sumMax = sequence[0]
    for (i in 1 until n) {
        if ( isPositive(sequence,i-1)&& isValuable(sequence,i)) {
            sequence[i] += sequence[i - 1]
        }
        if (sumMax < sequence[i]) {
            sumMax = sequence[i]
        }
    }
    println(sumMax)
}

fun isValuable(sequence: Array<Int>, i: Int): Boolean {
    return sequence[i] + sequence[i - 1] > 0
}

fun isPositive(sequence: Array<Int>, i: Int):Boolean{
    return sequence[i] > 0
}
