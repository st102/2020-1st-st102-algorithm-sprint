import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

fun main() {
    val bufferReader = BufferedReader(InputStreamReader(`in`))
    val T = bufferReader.readLine().toInt()
    for (case in 0 until T) {
        val N = bufferReader.readLine().toInt()
        val scores = Array<Pair<Int, Int>>(N) {
            val stringTokenizer = StringTokenizer(bufferReader.readLine())
            Pair(stringTokenizer.nextToken().toInt(), stringTokenizer.nextToken().toInt())
        }
        println(NewPerson().solution(scores))

    }
}

class NewPerson {
    fun solution(scores: Array<Pair<Int, Int>>): Int {
        val aTest = mutableListOf<Person>()
        val bTest = mutableListOf<Person>()
        scores.forEachIndexed { index, score ->
            aTest.add(Person(index, score.first, score.second))
            bTest.add(Person(index, score.first, score.second))
        }
        aTest.sortBy { it.aRank }
        val candidate = bTest.sortedBy { it.bRank }.subList(0, aTest.first().bRank - 1)
        var temp = Int.MAX_VALUE
        var count = 1
        candidate.forEach {
            if (it.aRank < temp) {
                temp = it.aRank
                count++
            }
        }
        return count
    }

    data class Person(
        val no: Int,
        val aRank: Int,
        val bRank: Int
    )
}