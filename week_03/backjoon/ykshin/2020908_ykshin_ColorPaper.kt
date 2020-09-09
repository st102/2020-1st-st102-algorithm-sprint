import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

const val COLOR_PAPER_SIZE = 10
const val BASE_PAPER_SIZE = 100
fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferedReader.readLine())
    val n = stringTokenizer.nextToken().toInt()
    val base = Array(BASE_PAPER_SIZE) { BooleanArray(BASE_PAPER_SIZE) }
    for (colorPaperIndex in 0 until n) {
        stringTokenizer = StringTokenizer(bufferedReader.readLine())
        val x = stringTokenizer.nextToken().toInt()
        val y = stringTokenizer.nextToken().toInt()
        for(xIndex in 0 until COLOR_PAPER_SIZE){
            for(yIndex in 0 until COLOR_PAPER_SIZE){
                base[xIndex+x][yIndex+y] = true
            }
        }
    }
    println(base.sumBy { line -> line.count { pixel-> pixel } })
}


