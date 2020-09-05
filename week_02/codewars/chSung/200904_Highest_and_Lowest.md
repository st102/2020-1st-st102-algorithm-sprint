# Highest And Lowest

## 문제 설명

*  스트링 타입으로 입력받은 숫자들의 최대, 최소값을 스트링 타입으로 출력

## 나의 풀이 방법

```java
import java.util.*;

public class Kata {
    public static String highAndLow(String numbers) {
        String[] tmp = numbers.split(" ");
        int[] result = new int[tmp.length];

        for (int i = 0; i < result.length; i++) {
            result[i] = Integer.parseInt(tmp[i]);
        }
        Arrays.sort(result);
        return Integer.toString(result[result.length - 1]) + " " + Integer.toString(result[0]);
    }
}
```

*  최근에는 문자열과 정수 자료형과의 형변환 관전 문제가 많았다. 연습을 좀 해둬서 어렵지 않게 풀 수 있었다.
*  string으로 받았기 때문에 임시 스트링 배열에 넣어서 split()메소드를 사용했고 결과를 담을 배열 result에다가 인덱스를 통해 넣어주었다.
*  오름차순 정렬함수는 구글링했다. 그리고 인덱스를 통해 최대, 최소를 뽑아냈다.



## 다른 사람의 풀이 방법

* ### Best Practice

```java
 import java.util.Arrays;

 public class Kata {
     public static String HighAndLow(String numbers) {

         int min = Arrays.stream(numbers.split(" "))
                         .mapToInt(i -> Integer.parseInt(i))
                         .min()
                         .getAsInt();

         int max = Arrays.stream(numbers.split(" "))
                         .mapToInt(i -> Integer.parseInt(i))
                         .max()
                         .getAsInt();

         return String.format("%d %d", max, min);
     }
 }
```

*  스트림을 이용해서 풀었고 코드를 한눈에 읽기 좋다. 근데 paring을 최대, 최소과정에서 2번 중복한다는 점이 단점 같다.

* ### Others

```java
public class Kata {
  public static String HighAndLow(String numbers) {
     int max = Integer.MIN_VALUE;
     int min = Integer.MAX_VALUE;
     String nums[] = numbers.split(" ");
     
     for(String s: nums) {
       int num = Integer.parseInt(s);
       
       max = Math.max(max, num);
       min = Math.min(min, num);
     }  
     
     return "" + max + " " + min;
  }
}
```

*  개인적으로 이 코드가 맘에 든다.  변수명도 명확하고 내것과 다르게 리턴문을 봤을 때 뭘 구했는지 딱 보여서 좋다

## 배운 점

*  스트링 타입과 정수 타입의 데이터 변환, 배열의 오름차순 sort

## 반성할 점

*   간단한 sort 함수도 잊어버렸다  이참에 오름차순, 내림차순, 부분만 정렬 등을 공부했다.

## Action Item

*   문제풀고 정리할 때 몰랐던 관련 개념들을 잘 정리하자
