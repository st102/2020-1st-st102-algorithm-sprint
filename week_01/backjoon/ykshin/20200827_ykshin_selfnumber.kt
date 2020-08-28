lateinit var era:Array<Boolean>

fun main(){
    era= Array(10001) { _ ->false}
    for(i in 1 until 10000){
        if(!era[i]) {
            println(i)
            check(i)
        }
    }
}

fun check(num:Int){
    if(num==0||num>10000||era[num]) return
    era[num]=true
    check(d(num))
}

fun d(num:Int) : Int{
    return num + num.toString().sumBy { it.toString().toInt() }
}