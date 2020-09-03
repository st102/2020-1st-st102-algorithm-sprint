# Disemvowel_Trolls

## 문제 설명

*  

## 나의 풀이 방법

```java
public class PhoneNumber {
	public static String createPhoneNumber(int[] numbers) {
	    return String.format("(%d%d%d) %d%d%d-%d%d%d%d",numbers[0],numbers[1],numbers[2],numbers[3],numbers[4],numbers[5],numbers[6],numbers[7],numbers[8],numbers[9]);
	  }
	}
```

*  어제 받은 피드백을 생각하여, concat이나 +연산자 등을 사용하지 않고 format을 사용하여 코딩을 하였다.

## 다른 사람의 풀이 방법

### Best Practice

```java
import java.util.stream.IntStream;

public class Kata {
  public static String createPhoneNumber(int[] numbers) {
    return String.format("(%d%d%d) %d%d%d-%d%d%d%d", IntStream.of(numbers).boxed().toArray());
  }
}
```
*   format을 사용하는것은 나와 같지만, 스트림을 사용하면서 코드가 더 간결해 보인다.

## 배운 점

*  format 메소드를 직접 사용해보니 조금 더 익숙해진거같다.



## 반성할 점

*  현재 자바 문법 공부도 병행하고 있는데 종종 다른사람의 코드를 보면 잘 모르는 문법이 있다.
*  빨리 공부해서 다음부터는 찾아보거나 이해하는 시간도 줄일 수 있도록 해야겠다.
