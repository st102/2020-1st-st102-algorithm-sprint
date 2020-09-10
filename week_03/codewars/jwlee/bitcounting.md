#Bit Counting

## 문제 설명
2진수로 변환한 수의 비트를 세서 반환

## 나의 풀이
```java
public class BitCounting {

  public static int countBits(int n){
    
    return Integer.toBinaryString(n).replaceAll("0","").length();
  }
  
}
```
* integer 함수로 string 으로 바꾼다음 0을 지우고 길이를 리턴했다. 

## 다른 사람 풀이
```java
public class BitCounting {

  public static int countBits(int n){
    return (int) Integer.toBinaryString(n).chars()
              .filter(c -> c == '1')
              .count();
  }
  
}
```
* 이렇게 풀고 싶었는데filter 를 떠올리지 못했다. 

```java
public class BitCounting {

  public static int countBits(int n){
    
    return Integer.bitCount(n);
  }
  
}
```
* 세주는 메소드가 있었다. 알아두자!

## 테스트 코드
```java
package package1;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Bitcountingtest {

	@Test
	void testCountBits() {
		
		assertEquals(5, BitCounting.countBits(1234));
		assertEquals(2, BitCounting.countBits(10));
		
	}

}
```
1234와 10으로 실험해 봤다. 초록불이 떴다! 그런데 태형선배님 저번에 말한 한 테스트 메소드에 여러개의 assert 문 쓰기보단 각각 나눠주면 좋을 것 같다는 말이 어떤 뜻인지 잘 모르겠습니다ㅠㅠ

## 배운 점
* 가야할 길이 멀다.

## 반성할 점
* 스트림에 대해 기초부터 공부해야하는데 어떻게 해야할지 모르겠다. 
