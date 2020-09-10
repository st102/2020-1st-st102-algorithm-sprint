# Bit Counting

## 문제 설명

*  

## 나의 풀이 방법

```java
package Cote_Package;

public class Bit_Count {
	public static int countBits(int n){
		String onebit = Integer.toBinaryString(n).replaceAll("0","");
		return onebit.length();
	}
}

```

*  먼저 숫자를 2진화시키고 0을 없애면서 1만 남은 문자열이 생기므로 그 길이를 반환하였다.
*  별도 문자열 변수 선언없이 반환하려했지만, 뭔가 가독성이 떨어져보여 변수를 선언하였다.


## 테스트 코드
```java
package Cote_Package;
import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class Test_Bit {
		@Test
    public void test() {
			assertEquals(5, Bit_Count.countBits(1234));
	    assertEquals(1, Bit_Count.countBits(4));
	    assertEquals(3, Bit_Count.countBits(7));
	    assertEquals(2, Bit_Count.countBits(9));
	    assertEquals(2, Bit_Count.countBits(10));
    }
}

```
*  코드워즈의 테스트코드를 베꼈다.


## 다른 사람의 풀이 방법

### Best Practice

```java
public class BitCounting {
  public static int countBits(int n){    
    return Integer.bitCount(n);
  }  
}
```
*   bitCount라는 메소드를 처음 봤고, 앞으로 이런 문제에 사용하면 좋을거같다.


## 배운 점

*  bitCount라는 메소드를 알게되었다.


## 반성할 점

*  TDD에 관한 유튜브영상을 보면서 공부하고있는데, 아직 확실하게 이해하진 못해서 복습을 하고있다.
*  다음 번에는 TDD를 적용하여 문제를 풀도록 노력해야겠다.
