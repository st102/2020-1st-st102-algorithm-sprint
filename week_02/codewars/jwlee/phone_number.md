# Create Phone Number

## 문제 설명

* 입력된 배열로 폰 번호를 만들어 리턴

## 나의 풀이 방법

```java
public class Kata {
  public static String createPhoneNumber(int[] numbers) {

    return String.format("(%d%d%d) %d%d%d-%d%d%d%d", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4], numbers[5], numbers[6], numbers[7], numbers[8], numbers[9]);

  }
}
```

```java
public class Kata {
  public static String createPhoneNumber(int[] numbers) {

  StringBuilder sb = new StringBuilder("(");
    for(int i = 0;i < 3;i++) {
      sb.append( numbers[i] );
    }
    sb.append(") ");
    for(int i = 3;i < 6;i++) {
      sb.append( numbers[i] );
    }
    sb.append("-");
    for(int i = 6;i < 10;i++) {
      sb.append( numbers[i] );
    }

    return sb.toString();
  }
}
```

* 어제 문제로 알게된 String format 을 사용했다.
* 처음엔 아래 방법으로 풀었는데, 가독성을 너무 해치는 것 같아서 바꾸었다. 


## 다른 사람의 풀이 방법
```java
public class Kata {
  public static String createPhoneNumber(int[] numbers) {
    String phoneNumber = new String("(xxx) xxx-xxxx");

    for (int i : numbers) {
      phoneNumber = phoneNumber.replaceFirst("x", Integer.toString(i));
    }

    return phoneNumber;
  }
}
```
* 스트링으로 미리 폼을 만들어 놓고 replace 하는 방식으로 풀이했다. 똑똑한 것 같다.
Made a String phone number form at first, and replaced it. 

## 배운 점
* 매번 메소드 호출 형식을 까먹어서 구글링했었는데 이젠 안보고도 쓸 수 있게 되었다.


## 반성할 점
* 오늘은 딱히 없었따!

