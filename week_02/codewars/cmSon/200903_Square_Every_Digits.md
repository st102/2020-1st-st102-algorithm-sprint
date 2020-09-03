# Square Every Digit

## 문제 설명

*  각자리 숫자를 제곱하여 연결한 숫자를 만들어라
*  ex) 9119 -> 81 1 1 81 = 811181

## 나의 풀이 방법

### 문제 풀이 코드

```java
public class SquareDigit {

  public int squareDigits(int n) {
    String square_of_digits="";
     while(n != 0){
	      square_of_digits = Integer.toString((int)Math.pow(n%10, 2)) + square_of_digits;
	      n /= 10;
	    }
    return  Integer.parseInt(square_of_digits);
  }

}
```
*  각자리 숫자의 제곱을 1의 자리부터 구해 문자열 앞에다 붙이는 방식을 사용하였다.
*  while문내에서 n값을 계속 10씩으로 나누어 모든 자리수의 숫자를 구할수 있게 하였다.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class SquareDigit {

  public int squareDigits(int n) {
    String result = ""; 
    
    while (n != 0) {
      int digit = n % 10 ;
      result = digit*digit + result ;
      n /= 10 ;
    }
    
    return Integer.parseInt(result) ;
  }

}
```

### Clever

```java
public class SquareDigit {

  public int squareDigits(int n) {
    String result = ""; 
    
    while (n != 0) {
      int digit = n % 10 ;
      result = digit*digit + result ;
      n /= 10 ;
    }
    
    return Integer.parseInt(result) ;
  }

}
```

*  나랑 같은 방식으로 이용해지만 코드의 가독성의 나보다 훨씬 뛰어나다.
*  너무 내가 자바에서 제공해주는 함수를 이용하는데 집착했던거 같다.

## 배운 점 

*  떄로는 언어에서 제공해주는 함수를 이용하지 않는게 더 깔끔한 코드를 만들어 내는 거 같다.

## 반성할 점
 
 *  배운 점에서 말한것처럼 함수를 잘 이용하면 좋지만 너무 간단한 상황까지 굳이 함수로 처리할 필요는 없는거 같다.

## Action Item

*  매번 하는 적는 이야기인거 같다. 간단한게 최고다! 복잡하게 생각하지 말자!
*  그리고 java는 어렵다.. 이 문제에서 C++이 제공이 안되서 java를 사용했는데 헷갈리는 부분이 많다.