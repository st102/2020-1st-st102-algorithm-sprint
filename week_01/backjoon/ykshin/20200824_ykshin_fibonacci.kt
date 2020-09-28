fun main() {
    val n = readLine()?.toInt() ?: return
    println(fibo(n))
}

fun fibo(n:Int) : Int{
    if(n<=0) return 0
    else if(n==1) return 1
    else return fibo(n-1)+fibo(n-2)
}