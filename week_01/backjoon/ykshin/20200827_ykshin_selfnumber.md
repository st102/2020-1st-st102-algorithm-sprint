# {셀프 넘버}

## 문제 설명
함수 d가 있고, n을 d(n)의 생성자라고 할떄, 10000이하의 정수중 생성자가 없는 숫자를 모두 찾아 출력하라.

## 나의 풀이 방법
에라토스테네스의 체를 이용해 1부터 만들수 있는 수를 체크한다.
main을 통해 방문된 숫자는 아직 방문이 안된 숫자이니 생성자가 없다는 뜻이다. 따라서 출력하고, check함수를 통해 해당 정수로 만들 수 있는 숫자를 재귀로 만들어간다.
```kotlin
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
```

## 다른 사람의 풀이 방법
set을 이용해 해당 숫자가 방문이 되었는지를 탐색한다.
```python
  def get_no_self_number(element):
        string_element = str(element)
        no_self_number = element
        for number in range(len(string_element)):
            no_self_number += int(string_element[number])
        return no_self_number

    no_self_number_set = set()

    for index in range(1, 10000 + 1):
        if index not in no_self_number_set:
            print(index)

        no_self_number_set.add(get_no_self_number(index))
```

## 배운 점
- set을 이용해 해당 값이 방문되었는지 체크할 수 있다는 것을 배웠다.
- char형을 toInt로 변환하면 ascii code에 해당하는 값이 나오는 것 같다.

## 반성할 점
- char형을 자주 다뤄보지 못해서 간단한 메소드도 잘 못 사용했다.

## Action Item
- 꾸준히 계속 풀자!