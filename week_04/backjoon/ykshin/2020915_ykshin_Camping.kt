import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    lateinit var stringTokenizer: StringTokenizer
    var case = 0
    while (true) {
        case++
        stringTokenizer = StringTokenizer(bufferReader.readLine())
        val L = stringTokenizer.nextToken().toInt()
        val P = stringTokenizer.nextToken().toInt()
        val V = stringTokenizer.nextToken().toInt()
        if (L == 0 && P == 0 && V == 0) return
        println("Case ${case}: ${Camping().solution(L, P, V)}")
    }
}

class Camping {
    fun solution(L: Int, P: Int, V: Int): Int {
        return V / P * L + min(V % P, L)
    }
}