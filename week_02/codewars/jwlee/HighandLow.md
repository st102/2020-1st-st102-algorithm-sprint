# Highest And Lowest

## 문제 설명

* 스트링으로 받은 입력의 최대, 최소값 출력

## 나의 풀이 방법

```java
public class Kata {
  public static String highAndLow(String numbers) {
    String[] split = numbers.split(" ");
    int min, max = Integer.parseInt(split[0]);

    String result = "";

    for(int i = 0; i < split.length; i++) {

    if(min > Integer.parseInt(split[i]))
      min = Integer.parseInt(split[i]);

    if(max < Integer.parseInt(split[i]))
      max = Integer.parseInt(split[i]);

    }
    return max + " " + min;
  }
}
```
* split 으로 잘라 배열에 넣고, min 과 max 를 구했다. 중복되는 부분이 많은 듯 하다.

## 다른 사람 풀이 방법

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
* 스트림을 이용했다. 이렇게 쓸 수있구나 무릎을 탁 쳤다 

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
* 가독성이 아주 좋은 것 같다.

## 배운 점

* 나도 모르게 문제를 읽고 쉽게 판단내려서 그냥 생각없이 푼 경우가 많은가보다. 앞으로 다른 방법을 이용해서 풀 수 있나 고민을 하는 시간을 가져야겠다. 

## 반성할 점
* 최대, 최소라길래 아무 생각 없이 계산해서 코드를 막 쓴 것 같다.. 다른 코드들을 보니 내 코드는 쓰레기다

## Action Item
* 다른 코드들 따라 쳐보고 관련 함수, 스트림 등에 대해 공부하기

