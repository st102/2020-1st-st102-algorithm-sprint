# Highest and Lowest

## 문제 설명

*  

## 나의 풀이 방법

```java
public class High_Low {
    public static String highAndLow(String numbers) {
        int[] digits = Stream.of(numbers.split(" ")).mapToInt(Integer::parseInt).toArray();
        Arrays.sort(digits);
        return String.format("%d %d", digits[digits.length - 1], digits[0]);
    }
}
```

*  스트림을 사용해 입력받은 문자열의 숫자들을 하나씩 쪼개 int형 배열에 넣은후 sort메소드를 통해 배열을 정렬하였다.
*	 그 후 정렬된 배열을 통해 큰수와 작은수를 반환했다.

## 다른 사람의 풀이 방법

### Best Practice

```java
import java.util.Arrays;
public class Kata {
  public static String HighAndLow(String numbers) {
    int[] num = Arrays.stream(numbers.split(" ")).mapToInt(Integer::parseInt).toArray();
    Arrays.sort(num);
    return num[num.length-1]+ " " + num[0];
  }
}
```
*   내 코드와 알고리즘은 거의 유사하다.(문자열을 int형 배열로 받고, sort를 통해 정렬후 반환)
*   내가 format을 통해 반환한거와 달리 그냥 +연산자를 사용해서 반환하였다.

## 배운 점

*  예전에도 문자열을 반환할 때, +연산자를 사용 or format을 사용하는걸로 고민을 많이 했었는데, 자주 보다보니까 각각 언제 써야 할지 보이는거 같다.


## 반성할 점

*  이번은 딱히 없었다.
