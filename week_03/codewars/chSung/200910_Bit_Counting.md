# Bit Counting

## 문제 설명

*  정수를 입력받아 그 정수의 이진표현에서 1의 갯수를 반환하라

## 나의 풀이 방법

```java
public class BitCounting {

  public static int countBits(int number){
    String tmp_s = Integer.toBinaryString(number);
    return  tmp_s.length() - tmp_s.replace("1", "").length();
  }
  
}
```

*  그동안 스트링을 통해 갯수를 구하거나 길이를 구하는 문제가 많아서 스트링에 넣을 생각부터 했다.
*  임시용 스트링에다가 숫자를 이진수로 저장하고 그 길이에서 1이 아닌것들을 만들어 빼준다.
*  이제보니까 그냥 0으로 replace하는게 더 편했다..



## 다른 사람의 풀이 방법

* ### Best Practice

```java
 public class BitCounting {

   public static int countBits(int n){
     
     return Integer.bitCount(n);
   }
   
 }

```

*  bitCount() 라는 메소드를 알고 있었다면 한줄컷이였다.

* ### Clever

```java
public class BitCounting {

  public static int countBits(int n){
    int ret = n % 2;
    while ((n /= 2) > 0) ret += n % 2;
    return ret;
  }
  
}
```

*  10진수를 2진수로 바꾸는 과정을 잘 재현했다. 반복적으로 2로 나눠주고 그 나머지 연산을 통해 1의 갯수를 구했다. 신박하다

## 배운 점

*  비트연산에 대해 한번 복습했다. 오래동안 안쓰니까 다 까먹었었다.
*  bitCount() 메소드

## 반성할 점

*  replace를 0으로 했으면 더 좋았다.

## Action Item

*   string에 대해 완벽히 배운건 아니였지만 이렇게 한문제 한문제 공부하면서 풀다보니까 어느새 익숙해졌다. 계속 꾸준히 하자

