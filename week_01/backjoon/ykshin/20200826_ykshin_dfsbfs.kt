import java.util.*
import kotlin.collections.ArrayList

data class Node(var visited: Boolean = false, var link: ArrayList<Int> = ArrayList<Int>())

lateinit var dfsNodeList: Array<Node>
lateinit var bfsNodeList: Array<Node>
var n = 0
var m = 0
var v = 0
fun main() {
    val sc = Scanner(System.`in`)
    n = sc.nextInt()
    m = sc.nextInt()
    v = sc.nextInt()
    dfsNodeList = Array(n + 1) { _ -> Node() }
    bfsNodeList = Array(n + 1) { _ -> Node() }
    for (i in 0 until m) {
        val a = sc.nextInt()
        val b = sc.nextInt()
        dfsNodeList[a].link.add(b)
        dfsNodeList[b].link.add(a)
        bfsNodeList[a].link.add(b)
        bfsNodeList[b].link.add(a)
    }
    for (i in 1..n) {
        dfsNodeList[i].link.sort()
        bfsNodeList[i].link.sort()
    }
    dfs(v)
    println()
    bfs(v)
}

fun dfs(now: Int) {
    print("$now ")
    dfsNodeList[now].visited = true
    for (next in dfsNodeList[now].link) {
        if (!dfsNodeList[next].visited) {
            dfs(next)
        }
    }
}

fun bfs(first: Int) {
    val queue = ArrayList<Int>()
    queue.add(first)
    bfsNodeList[first].visited = true
    while (queue.isNotEmpty()) {
        val now = queue.first()
        print("$now ")
        queue.removeAt(0)
        for (next in bfsNodeList[now].link) {
            if (!bfsNodeList[next].visited) {
                queue.add(next)
                bfsNodeList[next].visited = true
            }
        }
    }
}
