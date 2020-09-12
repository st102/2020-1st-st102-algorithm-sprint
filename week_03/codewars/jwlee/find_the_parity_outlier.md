# Find The Parity Outlier

## 문제 설명
주어진 정수 배열에서 아싸를 골라 리턴하라.

## 나의 풀이
```java
import java.util.Arrays;

public class FindOutlier{
  static int find(int[] integers){
    
  int[] odd = Arrays.stream(integers)
                .filter(i -> (i % 2 == 0))
                .toArray();
  int[] even = Arrays.stream(integers)
                 .filter(i -> (i % 2 != 0))
                 .toArray();
    
    
  return odd.length > 1 ? even[0] : odd[0];
}}
```
* 스트림을 이용해서 배열을 생성해서 넣고, 길이가 1인 배열의 0 인덱스를 리턴한다.

## 다른 사람 풀이

```java
public class FindOutlier {

    static int find(int[] integers) {
        int oddcount = 0, odd = 0, evencount = 0, even = 0;
        for (int i : integers) {
            if (i % 2 == 0) {
                even = i;
                evencount++;
            } else {
                odd = i;
                oddcount++;
            }
            if (evencount > 0 && oddcount > 0) {
                if (evencount > 1) {
                    return odd;
                } else if (oddcount > 1) {
                    return even;
                }
            }
        }
        return evencount > 1 ? odd : even;
    }
}
```
* 처음에 이렇게 풀었는데 스트림이 훨씬 간결해보여서 썼다. 
```java
import java.util.Arrays;

public class FindOutlier{
    public static int find(int[] integers) {
       
        int sum = Arrays.stream(integers).limit(3).map(i -> Math.abs(i) % 2).sum();
        int mod = (sum == 0 || sum == 1) ? 1 : 0;

        return Arrays.stream(integers).parallel().filter(n -> Math.abs(n) % 2 == mod).findFirst().getAsInt();
    }
}
```
* 첫 3개의 원소만 더해서 2로 나눴을 때 0이나 1이면 홀수이다. 라는 아이디어로 홀수짝수를 판별했다. 천재다.

## 테스트 코드

```java
package package1;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

class Bitcountingtest {

	@Test
	void testCountBits() {

		//Given :
		int[] testnumber1 = {2, 4, 6, 8, -10, 3};
		int[] testnumber2 = {Integer.MAX_VALUE, 0, 1};


		//when :
		int result = BitCounting.countBits(testnumber1);
		int result2 = BitCounting.countBits(testnumber2);

		//then :
		result = 3;
		result2 = 0;
	}
}

```
* Given, when, then 을쓰고 이번엔 assert 문 말고 직접비교해봤다. 잘돌아간다!

## 배운점
* 시간을 정해놓고 푸니까 좋은 것 같다.
* 스트림 새로운 메소드

## 반성할 점
* 오늘은 딱히 없었다.
