import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.lang.System.`in`
import java.util.*

val sb :StringBuilder by lazy{
    StringBuilder()
}

fun main() {
    val br = BufferedReader(InputStreamReader(`in`))
    val n = br.readLine().toInt()
    val people = mutableListOf<Pair<Int,Int>>()
    val st = StringTokenizer(br.readLine())
    for(i in 0 until n){
        people.add(Pair(i,st.nextToken().toInt()))
    }
    oneLineSort(people)
    people.forEach {
        sb.append("${it.first+1} ")
    }
    println(sb)

}

fun oneLineSort(people: MutableList<Pair<Int, Int>>) {
    val n = people.size
    for(i in n-2 downTo 0){
        val person = people[i]
        people.removeAt(i)
        people.add(i+person.second,person)
    }
}