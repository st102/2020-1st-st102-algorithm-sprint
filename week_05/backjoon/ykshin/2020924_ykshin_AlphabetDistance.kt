import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Math.abs
import java.lang.System.`in`
import java.util.*

lateinit var gates: IntArray

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    val T = bufferedReader.readLine().toInt()
    repeat(T) {
        val stringTokenizer = StringTokenizer(bufferedReader.readLine())
        val str1 = stringTokenizer.nextToken()
        val str2 = stringTokenizer.nextToken()
        println("Distances: ${AlphabetDistance().solution(str1, str2)}")
    }
}

class AlphabetDistance {
    fun solution(str1: String, str2: String) : String{
        return str1.mapIndexed {
            index, _ ->
            distance(str1[index],str2[index])
        }.joinToString(" ")
    }

    private fun distance(c1: Char, c2: Char): Int {
        var a = c2 - c1
        if(a<0){
            a += 26
        }
        return a
    }
}
