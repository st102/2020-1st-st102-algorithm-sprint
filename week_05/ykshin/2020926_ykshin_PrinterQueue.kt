fun main() {
    repeat(readLine()!!.toInt()) {
        val (N, M) = readLine()!!.split(" ").map { it.toInt() }

        println(PrinterQueue(N, M).solution())

    }
}

class PrinterQueue(val N: Int, val M: Int) {
    val queueList = Array<MutableList<Int>>(10) {
        mutableListOf()
    }
    var targetPriority = 0
    lateinit var mainQueue: MutableList<Pair<Int, Int>>
    fun solution(): Int {
        mainQueue = readLine()?.split(" ")!!.mapIndexed { index, priority ->
            queueList[priority.toInt()].add(index)
            if (index == M) {
                targetPriority = priority.toInt()
            }
            Pair(index, priority.toInt())
        }.toMutableList()

        var nowIndex = 0
        var nowPrirority = 9
        var nowPrirortyQueue = queueList[nowPrirority]
        var count = 1
        while (true) {
            if (nowPrirortyQueue.isEmpty()) {
                nowPrirority--
                nowPrirortyQueue = queueList[nowPrirority]
                continue
            }
            if (isTarget(nowPrirority, nowIndex)) {
                return count
            }
            if (canPrint(nowPrirortyQueue,nowIndex)){
                nowPrirortyQueue.remove(mainQueue[nowIndex].first)
                mainQueue.removeAt(nowIndex)
                count++
            }else{
                nowIndex++
            }
            if(nowIndex >= mainQueue.size){
                nowIndex = 0
            }
        }
    }

    private fun canPrint(nowPrirortyQueue: MutableList<Int>, nowIndex: Int): Boolean {
        return nowPrirortyQueue.contains(mainQueue[nowIndex].first)
    }

    private fun isTarget(nowPrirority: Int, nowIndex: Int): Boolean {
        return nowPrirority == targetPriority && mainQueue[nowIndex].first == M
    }
}
