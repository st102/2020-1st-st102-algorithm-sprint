import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    val stringTokenizer = StringTokenizer(bufferReader.readLine())
    val A = stringTokenizer.nextToken().toInt()
    val B = stringTokenizer.nextToken().toInt()
    val C = stringTokenizer.nextToken().toInt()
    val N = stringTokenizer.nextToken().toInt()
    println(RoomAlloting().solution(A, B, C, N))
}

class RoomAlloting {
    lateinit var dp: BooleanArray
    fun solution(a: Int, b: Int, c: Int, n: Int): Int {
        dp = BooleanArray(n + 1)
        if(a<=n) dp[a] = true
        if(b<=n) dp[b] = true
        if(c<=n) dp[c] = true
        for (i in 1..n) {
            if (isOk(i - a) || isOk(i - b) || isOk(i - c)) {
                dp[i] = true
            }
        }
        return if (dp[n]) 1 else 0
    }

    private fun isOk(i: Int): Boolean {
        return i > 0 && dp[i]
    }
}