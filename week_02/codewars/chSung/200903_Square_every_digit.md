# Square Every Digit

## 문제 설명

*  입력받은 int형 숫자의 자릿수를 각각 제곱해서 int형으로 반환하라

## 나의 풀이 방법

```java
public class SquareDigit {

    public int squareDigits(int num) {
        String square_num = "";

        while (num != 0) {
            int digit = num % 10;
            square_num = digit * digit + square_num;
            num /= 10;
        }

        return Integer.parseInt(square_num);
    }

}
```

*  int형 숫자 그대로 갖고 놀다가 반환하려고 시간을 엄청 써봤는데 못했다... 이건 주말에 더 해볼꺼다
뭔가 될것 같으면서 안됐다...
*  문제의 의도대로라면 저 숫자를 스트링에 담았다가 다시 인트형으로 바꾸는걸 원하는 것 같다. 
저번 알고리즘에서 다뤘었기 때문에 나머지연산과 /= 대입연산으로 풀기 쉬웠는데 스트링을 int형으로 바꾸는 법을 몰라서 구글링으로 찾았다.



## 다른 사람의 풀이 방법

* ### Best Practice

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

*  내 풀이랑 아주 똑같다. 카피 검사가 있었다면 걸렸을 것이다. 지금 보면 result=와 n/= 두 순서가 중요하다

* ### Clever

```java
import java.util.stream.Collectors;

public class SquareDigit {

    public int squareDigits(int n) {
        return Integer.parseInt(String.valueOf(n)
                                      .chars()
                                      .map(i -> Integer.parseInt(String.valueOf((char) i)))
                                      .map(i -> i * i)
                                      .mapToObj(String::valueOf)
                                      .collect(Collectors.joining("")));
    }

}
```

*  람다식 이라고 하는데 이해가 잘 안간다.. 

## 배운 점

*  스트링에 담겨있는 숫자를 정수형으로 바꾸는 방법을 배웠다.
*  숫자와 digit 관계는 나머지 연산과 (몫, 저장변수) 로 잘 다룰 수있다.

## 반성할 점

*   문법 개념이 부족하다보니 다른 사람 코드를 읽을 수조차 없었다 

## Action Item

*   오늘 한 문제를 너무 오래 풀었다. 다음 문제부터는 시간제한을 정하고 넘어가도록 하자
