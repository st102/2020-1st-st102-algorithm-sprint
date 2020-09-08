import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.Integer.min
import java.lang.System.`in`
import java.util.*

data class Person(
    val height: Int = 0,
    val weight: Int = 0
)

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferedReader.readLine())
    val n = stringTokenizer.nextToken().toInt()

    val people = mutableListOf<Person>()
    for (i in 0 until n) {
        stringTokenizer = StringTokenizer(bufferedReader.readLine())
        people.add(Person(stringTokenizer.nextToken().toInt(), stringTokenizer.nextToken().toInt()))
    }

    val stringBuffer = StringBuffer()
    people.forEach { person->
        stringBuffer.append("${people.count {
            it.height>person.height&&it.weight>person.weight
        } + 1} ")
    }

    println(stringBuffer)
}


