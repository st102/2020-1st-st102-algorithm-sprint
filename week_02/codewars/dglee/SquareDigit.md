# Disemvowel_Trolls

## 문제 설명

*  

## 나의 풀이 방법

```java
package Cote_Package;
import java.util.stream.Stream;

public class SquareDigit {
    public int squareDigits(int n) {
        String output = "";
        int[] digits = Stream.of(String.valueOf(n).split("")).mapToInt(Integer::parseInt).toArray();

        for (int i = 0; i < digits.length; i++) {
            output += String.valueOf(digits[i] * digits[i]);
        }

        return Integer.parseInt(output);
    }
}
```

*  스트림을 사용해 정수 n을 하나씩 쪼개 int형 배열에 넣었다. 그 후 문자열에 하나씩 추가하고 형변환을 시킨 뒤 반환하였다.
*	 스트림을 사용한 방법은 내가 스스로 한것은 아니고, 스트림을 통해 변수를 배열로 변환시키는 방법을 찾아 사용하였다.

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
*   배열을 사용하지 않고, 정수 n을 한자리씩 나눠서 코딩을 하였다.
*   처음 내가 생각했던 방법이였는데, 막상 쓰고보니 이 코드가 훨씬 간결해보인다.

## 배운 점

*  구글링 실력이 늘어나고있고, 처음에 잘 사용하지 않아 생소했던 문법들을 자주 사용하면서 익숙해지고있다.


## 반성할 점

*  어려운 문법을 사용한다고 좋은 코드가 아니며, 오히려 가독성을 해치고 쓸데없는 내용이 많이진다고 느꼈다.
