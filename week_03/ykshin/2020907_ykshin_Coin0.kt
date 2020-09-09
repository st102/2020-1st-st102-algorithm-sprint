import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferedReader.readLine())
    val n = stringTokenizer.nextToken().toInt()
    val k = stringTokenizer.nextToken().toInt()
    val coins = IntArray(n)
    for(i in 0 until n){
        coins[i] = StringTokenizer(bufferedReader.readLine()).nextToken().toInt()
    }

    var sum = k
    var count = 0
    for(i in coins.size-1 downTo 0){
        val no = sum / coins[i]
        count+=no
        sum-=no * coins[i]
    }


    println(count)
}


