# Pertfect Square

## 문제설명
제곱근을 구해서 +1 해서 반환하라

## 나의 풀이
```java
import java.lang.*;

public class NumberFun {
  public static long findNextSquare(long sq) {
      
    double a = Math.sqrt(sq);
    
    return (a % 1 == 0)? (long)Math.pow(a+1,2) : -1;
  
  }
}
```
* Math 클래스를 이용해서 풀이했다.

## 다른 사람 풀이
* 다 똑같은 것 같다. 

## 배운 점
* Math 클래스 제곱근함수를 다시볼 수 있었따! 소문자 대문자 자꾸 헷갈린다.

## 반성할 점
* 게을러지지말자...
