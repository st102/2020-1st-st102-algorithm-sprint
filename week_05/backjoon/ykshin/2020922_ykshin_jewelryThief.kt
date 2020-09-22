import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*


fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferedReader.readLine())
    val N = stringTokenizer.nextToken().toInt()
    val K = stringTokenizer.nextToken().toInt()
    val jewelryList = Array<Pair<Int, Int>>(N) {
        stringTokenizer = StringTokenizer(bufferedReader.readLine())
        Pair(stringTokenizer.nextToken().toInt(), stringTokenizer.nextToken().toInt())
    }
    val bagList = IntArray(K) {
        bufferedReader.readLine().toInt()
    }
    println(JewelryThief().solution(N, jewelryList, bagList))
}

class JewelryThief {
    fun solution(N: Int, jewelryList: Array<Pair<Int, Int>>, bagList: IntArray): Long {
        var sum = 0L
        val priorityQueue = PriorityQueue<Int>(compareBy { -it })
        jewelryList.sortBy { it.first }
        bagList.sort()
        var jewelryListIndex = 0
        bagList.forEach { bagSize ->
            while (jewelryListIndex < N && jewelryList[jewelryListIndex].first<=bagSize) {
                priorityQueue.add(jewelryList[jewelryListIndex].second)
                jewelryListIndex++
            }
            if(priorityQueue.isNotEmpty()){
                sum+=priorityQueue.poll()
            }
        }
        return sum
    }
}