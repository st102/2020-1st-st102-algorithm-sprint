import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.max
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferReader.readLine())
    val N = stringTokenizer.nextToken().toInt()
    val consultList = Array<Pair<Int, Int>>(N) {
        stringTokenizer = StringTokenizer(bufferReader.readLine())
        Pair(stringTokenizer.nextToken().toInt(), stringTokenizer.nextToken().toInt())
    }
    println(Quit().solution(N, consultList))
}

class Quit {
    fun solution(n: Int, consultList: Array<Pair<Int, Int>>): Int {
        val dp = IntArray(n)
        dp[n-1] = if(consultList[n-1].first==1) consultList[n-1].second else 0
        for (day in n - 2 downTo 0) {
            val consult = consultList[day]
            val nextDay = consult.first + day
            if (nextDay <= n) {
                dp[day] = max(consult.second + if(nextDay==n) 0 else dp[nextDay], dp[day+1])
            }else{
                dp[day]=dp[day+1]
            }
        }
        return dp[0]
    }
}