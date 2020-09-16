# {신입사원}

## 문제 설명
두가지 시험에 대한 순위를 가진 사람들이 주어질 때 주어진 조건에 맞는 사람의 수를 구하는 문제
조건 : 둘 중 하나라도 다른 지원자보다 안떨어지는 사람


## 나의 풀이 방법
1. A시험에 대해서 1등의 B시험 순위를 구한다 
2. B시험이 A시험 1등보다 못본사람은 다 탈락
3. 남은 사람들 중 B순위가 높은 순서대로 본인보다 B순위가 높은사람이 A도 높은지 검사
4. 만약 B순위가 다른사람보다 낮은데, A순위도 낮으면 탈락
```kotlin
 fun solution(scores: Array<Pair<Int, Int>>): Int {
         val aTest = mutableListOf<Person>()
         val bTest = mutableListOf<Person>()
         scores.forEachIndexed { index, score ->
             aTest.add(Person(index, score.first, score.second))
             bTest.add(Person(index, score.first, score.second))
         }
         aTest.sortBy { it.aRank }
         val candidate = bTest.sortedBy { it.bRank }.subList(0, aTest.first().bRank - 1)
         var temp = Int.MAX_VALUE
         var count = 1
         candidate.forEach {
             if (it.aRank < temp) {
                 temp = it.aRank
                 count++
             }
         }
         return count
     }
 
     data class Person(
         val no: Int,
         val aRank: Int,
         val bRank: Int
     )
```

## 다른 사람의 풀이 방법
동일하게 풀이했다.

## 배운 점
- sort와 sorted의 차이점

## 반성할 점
- 문제 이해를 확실히하자

## Action Item
- 문제에서 요구하는 조건을 확실히 정리하기