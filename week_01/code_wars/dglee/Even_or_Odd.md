# Vowel Count

## 문제 설명

*  주어진 정수가 홀수이면 "Odd" 짝수이면 "Even"을 리턴하라

## 나의 풀이 방법

```java
package Cote_Package;

public class Even_or_Odd {

    public static String even_or_odd(int num) {
        if (num % 2 == 0) {
            return "Even";
        }
        return "Odd";
    }
}
```

*   if문을 사용하는 방법말고 조건연산자를 사용하는 방법도 생각해봤지만 불필요한 String 변수선언이 있어서 이 방법대로 했다.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class EvenOrOdd {
    public static String even_or_odd(int number) {
        return (number%2 == 0) ? "Even" : "Odd";
    }
}
```
*   조건문 대신 조건 연산자를 사용하면서 코드가 짧아졌고, return에 모든 코드를 넣으면서 보기가 좋았다.

## 배운 점

*  return에 단순히 변수를 반환하는 것이 아닌 알고리즘을 넣어 코드를 간결하게 할 수 있다는걸 최근에 접하게 되었다. 앞으로 간단한 코딩의 경우에는 이 방법을 쓰는것을 습관화 해야겠다.

## 반성할 점

*  위 사람의 코드말고도 다른 사람의 코드들을 많이 보게 되었는데, if문 안에 내용이 1줄일 경우에는 중괄호를 쓰지 않았다. 평소에도 알고 있던 사실임에도 활용하지 않은 점을 반성하고, 이런 사소한 것도 습관화해 내 것으로 만들어야겠다.
