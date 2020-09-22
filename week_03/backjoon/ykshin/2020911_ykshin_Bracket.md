# {괄호}

## 문제 설명
괄호로 이루어진 문자열이 주어질 때, 괄호 짝이 올바른지 검사하는 문제


## 나의 풀이 방법
'(' 이면 스택에 넣고 ')'이면 팝한다. 팝하는 과정에서 스택이 비어있다면, 잘못됨.
모든 처리를 다했는데 스택에 남아있는게 있으면 잘못됨

```kotlin
 fun solution(str: String): String {
         val stack = Stack<Char>()
         str.forEach {
             when (it) {
                 '(' -> {
                     stack.push(it)
                 }
                 ')' -> {
                     if (stack.isEmpty()) {
                         return "NO"
                     }
                     stack.pop()
                 }
             }
         }
         return if (stack.isEmpty()) return "YES"
         else "NO"
     }
```

## 다른 사람의 풀이 방법
동일하게 풀이했다.

## 배운 점
- Stack 에서 add와 push의 차이점

## 반성할 점
- 꾸준히 풀쟈

## Action Item
- 꾸준히 풀자!