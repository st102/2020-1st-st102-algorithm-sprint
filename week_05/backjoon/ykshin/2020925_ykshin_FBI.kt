fun main() {
    println((1..5).map {
        if (readLine()!!.contains("FBI")) it else 0
    }.filter { it != 0 }.let {
        if (it.isEmpty()) "HE GOT AWAY!"
        else it.joinToString(" ")
    })
}


