import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`

val stringBuilder: StringBuilder by lazy {
    StringBuilder()
}

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    val s = bufferedReader.readLine()
    val alphabet = arrayOf(
        'a', 'b', 'c', 'd', 'e',
        'f', 'g', 'h', 'i', 'j',
        'k', 'l', 'm', 'n', 'o',
        'p', 'q', 'r', 's', 't',
        'u', 'v', 'w', 'x', 'y', 'z'
    )
    alphabet.forEach {
        stringBuilder.append("${s.indexOf(it)} ")
    }
    println(stringBuilder)
}
