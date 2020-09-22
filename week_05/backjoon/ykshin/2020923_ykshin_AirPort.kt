import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`

lateinit var gates: IntArray

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    val G = bufferedReader.readLine().toInt()
    val P = bufferedReader.readLine().toInt()
    gates = IntArray(G + 1) { it }
    var count = 0
    for (i in 0 until P) {
        val gi = bufferedReader.readLine().toInt()
        val docking = find(gi)
        if (docking == 0) {
            break
        }else{
            count++
            merge(docking,docking-1)
        }
    }
    println(count)
}
fun merge(g1 : Int, g2:Int){
    val a = find(g1)
    val b = find(g2)
    gates[a] = b
}
fun find(gi: Int): Int {
    if (gates[gi] == gi) {
        return gi
    }
    gates[gi] = find(gates[gi])
    return gates[gi]
}
