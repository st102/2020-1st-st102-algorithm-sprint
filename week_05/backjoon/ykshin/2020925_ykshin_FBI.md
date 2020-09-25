# {FBI}

## 문제 설명
FBI가 포함되어있는 문자열을 찾아 인덱스 출력 

## 나의 풀이 방법
코트린스럽게 짜보기 위해 메소드체인형태로 짜봤다.
```kotlin
  fun main() {
      println((1..5).map {
          if (readLine()!!.contains("FBI")) it else 0
      }.filter { it != 0 }.let {
          if (it.isEmpty()) "HE GOT AWAY!"
          else it.joinToString(" ")
      })
  }
  
  

```

## 다른 사람의 풀이 방법
동일하다

## 배운 점
- 코틀린짱

## 반성할 점
- 꾸준히 풀자

## Action Item
- 버닝!!