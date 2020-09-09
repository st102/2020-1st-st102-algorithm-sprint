import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.System.`in`
import java.util.*

data class Node(
    val linkedList: MutableList<Int> = mutableListOf(),
    var visited: Boolean = false
)

lateinit var nodeList: MutableList<Node>
fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(`in`))
    var stringTokenizer = StringTokenizer(bufferedReader.readLine())
    val n = stringTokenizer.nextToken().toInt()
    val m = stringTokenizer.nextToken().toInt()
    nodeList = MutableList(n) { Node() }
    for (i in 0 until m) {
        stringTokenizer = StringTokenizer(bufferedReader.readLine())
        val first = stringTokenizer.nextToken().toInt() - 1
        val second = stringTokenizer.nextToken().toInt() - 1
        nodeList[first].linkedList.add(second)
        nodeList[second].linkedList.add(first)
    }

    var count = 0
    nodeList.forEach { node ->
        if (node.visited) return@forEach
        count++
        dfs(node)
    }
    println(count)

}

fun dfs(node: Node) {
    if (node.visited) return
    node.visited = true
    node.linkedList.forEach {
        dfs(nodeList[it])
    }
}
