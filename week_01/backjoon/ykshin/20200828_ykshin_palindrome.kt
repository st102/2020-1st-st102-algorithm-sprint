import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.lang.System.`in`
import java.util.*


lateinit var dp: Array<BooleanArray>
lateinit var arr: IntArray

fun main() {
    val br = BufferedReader(InputStreamReader(`in`))

    val n = br.readLine().toInt()
    var st = StringTokenizer(br.readLine())
    arr = IntArray(n)
    for (i in 0 until n) {
        arr[i] = Integer.valueOf(st.nextToken())
    }
    dp = Array(n) { BooleanArray(n) }
    for(i in 0 until n){
        for(j in 0 until n-i){
            when (i) {
                0 -> {
                    dp[j][j] = true
                }
                1 -> {
                    dp[j][j+1] = arr[j] == arr[j+1]
                }
                else -> {
                    dp[j][j+i] = if(dp[j+1][j+i-1]){
                        arr[j] == arr[j+i]
                    }else{
                        false
                    }
                }
            }
        }
    }
    val m = br.readLine().toInt()
    val sb = StringBuilder()
    for(i in 0 until m ){
        st = StringTokenizer(br.readLine())
        val s =Integer.valueOf(st.nextToken()) - 1
        val e = Integer.valueOf(st.nextToken()) - 1
        sb.append("${if(dp[s][e]) 1 else 0}\n")

    }
    println(sb.toString())
}