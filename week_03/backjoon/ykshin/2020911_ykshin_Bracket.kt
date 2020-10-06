import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    val N = bufferReader.readLine().toInt()
    for (i in 0 until N) {
        println(Bracket().solution(bufferReader.readLine()))
    }
}

class Bracket {
    fun solution(str: String): String {
        val stack = Stack<Char>()
        str.forEach {
            when (it) {
                '(' -> {
                    stack.push(it)
                }
                ')' -> {
                    if (stack.isEmpty()) {
                        return "NO"
                    }
                    stack.pop()
                }
            }
        }
        return if (stack.isEmpty()) return "YES"
        else "NO"
    }
}