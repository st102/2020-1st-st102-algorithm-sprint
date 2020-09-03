# Create Phone Number

## 문제 설명

*  0~9 , 10개의 정수타입 배열을 받아 전화번호 형태로 반환하는 함수를 작성하라

## 나의 풀이 방법

```java
public class Kata {
    public static String createPhoneNumber(int[] numbers) {
        String phone_num = "";
        for (int i = 0; i < numbers.length; i++) {
            if (i == 0) phone_num += '(';
            else if (i == 3) phone_num += ") ";
            else if (i == 6) phone_num += '-';

            phone_num += numbers[i];
        }
        return phone_num;
    }
}
```

*  처음에는 아주 단순하게 배열에 요소를 쏙쏙 넣어 추가하면 안되나 했다. 그런데 자바는 배열의 길이를 늘일 수 없다고 한다.
*  새로운 string을 만들어 선별적으로 차례대로 집어 넣는 방법으로 했다.



## 다른 사람의 풀이 방법

* ### Best Practice

```java
 public class Kata {
   public static String createPhoneNumber(int[] numbers) {
     return String.format("(%d%d%d) %d%d%d-%d%d%d%d",numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],numbers[5],numbers[6],numbers[7],numbers[8],numbers[9]);
   }
 }
```

*  가장 단순한 방법이지만 가장 확실하다ㅋㅋ 다만 내 생각엔 문제 목표가 배열을 다뤄보는데 있을 것에 있을 것 같다. 이걸로는 format 메소드 사용법을 익힐 수 있겠다. 

* ### Clever

```java
public class Kata {
  public static String createPhoneNumber(int[] numbers) {
    return String.format("(%d%d%d) %d%d%d-%d%d%d%d", java.util.stream.IntStream.of(numbers).boxed().toArray());
  }
}
```

*  이건 이해가 잘 안간다.... boxed()는 intStream을 Stream으로 바꿔주는 거라고 하고...

## 배운 점

*  string.format 메소를 한번 더 배웠다. 단순하게 생각하는게 더 좋을때도 있는 것 같다.

## 반성할 점

*   ") " 에서 자꾸 '' 으로 시도하다가 에러가 났다. 기초가 부족한 탓이니까 지금 하는 문법 공부를 더 열심히 해야함.

## Action Item

*   개강하고 첫 부분 공부중이다 나오는 알고리즘마다 자바 문법내용을 정리해두자 해왔던 방법들은 까먹지 말자.

