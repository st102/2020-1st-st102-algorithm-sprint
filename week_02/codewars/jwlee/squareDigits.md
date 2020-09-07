# SquareDigits

## 문제 설명

입력받은 수의 제곱을 스트링으로 리턴한다.

## 나의 풀이 방법
```java
public class SquareDigit {

  public int squareDigits(int n) {

  String result = "";
  int digit = 0;

  if( n < 10 )
    return n * n;

  while ( n > 0 ) {
    digit = n % 10;
    result = digit * digit + result;
    n = n / 10;
  }
    return Integer.valueOf(result);
}
  }
```
* 1주차 때 재귀로 푼 문제와 비슷하다고 생각했다. 한자리 씩 분리해서 제곱해서 string 에 붙이고, int 로 리턴한다.
divide it to single digits, square and append string, return to int.

* StringBuilder 를 쓸까 생각했지만 맨 뒤의 치환식이 너무 길어질 것 같아 그냥 했다.

## 다른 사람의 풀이 방법

```java
public class SquareDigit {

  public int squareDigits(int n) {
      if (n < 10) return n * n;
      else {
        int h = squareDigits(n / 10);
        int l = n % 10;
        return Integer.parseInt(h + "" + l * l);
      }
  }

}

```
* 재귀를 사용하였다. 코드가 더 간결해졌고 이해하기 쉬워보인다.

## 배운점
* 아는 문법을 적절하게 사용하는 연습을 한 것 같다.

## 반성할 점
* 앞으로 제한 시간을 두고 풀어야겠다.
