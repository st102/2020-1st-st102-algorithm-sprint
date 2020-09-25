# {알파벳 거리}

## 문제 설명
두 문자열에서 같은 위치의 문자간의 거리를 출력하는 문제

## 나의 풀이 방법
각 문자간의 차가 0보다 작아지면 26을 더한다.
```kotlin
   fun solution(str1: String, str2: String) : String{
           return str1.mapIndexed {
               index, _ ->
               distance(str1[index],str2[index])
           }.joinToString(" ")
       }
   
       private fun distance(c1: Char, c2: Char): Int {
           var a = c2 - c1
           if(a<0){
               a += 26
           }
           return a
       }
```

## 다른 사람의 풀이 방법
(b[i] - a[i] + 26) % 26
애초에 26을 더한 거리를 구하고 26으로 나머지 연산을 하면 if분기가 필요없어진다.

## 배운 점
- 간단한 연산도 효율적인 방법이 존재한다.

## 반성할 점
- 간단하다고 보이는 대로 풀지 말자

## Action Item
- 생각하자 윤권아!!!