import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.lang.System.`in`

val sb :StringBuilder by lazy{
    StringBuilder()
}

fun main() {
    val br = BufferedReader(InputStreamReader(`in`))
    val n = br.readLine().toInt()
    primeFactorization(n)
    println(sb.toString())

}

fun primeFactorization(n: Int) {
    var now = n
    var last = 2
    while (now != 1){
        for(i in last .. now){
            if(now%i==0){
                now/=i
                sb.append("$i\n")
                last = i
                break
            }
        }
    }
}
