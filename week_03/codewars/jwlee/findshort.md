# Shortest Word

## 문제 설명
주어진 스트링에서 가장 짧은 단어를 리턴한다.

## 나의 풀이

```java
import java.util.Arrays;

public class Kata {
    public static int findShort(String s) {
        return Arrays.stream(s.split(" "))
                     .mapToInt(i -> i.length())
                     .min()
                     .getAsInt();         
          
    }
}
```
```java
import java.util.StringTokenizer;

public class Kata {
    public static int findShort(String s) {
        
      StringTokenizer arr = new StringTokenizer(s, " ");
      int min = s.length();
      
      while(arr.hasMoreTokens()) {
        String Token = arr.nextToken();
        if(min > Token.length())
          min = Token.length();
        
      }
      
      return min;
    }
}
```
* 첫번째 코드는 Stream을 이용해 풀이했고, 두번쨰는 StringTokenizer 을 이용했다.

## 다른 사람 풀이
```java
import java.util.stream.*;

public class Kata {
    public static int findShort(String s) {
        return Stream.of(s.split(" "))
          .mapToInt(i -> i.length())
          .min()
          .getAsInt();
    }
}
```
* 나와 비슷하다. 

## Testcase 작성
```java
package algo.test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import algo.algo;

class algotest {

@Test
void testFindShort() {
algo Al = new algo();
						
assertEquals(1,algo.findShort("u are the most beautiful poo"));
assertEquals(3,algo.findShort("bitcoin take over the world maybe who knows perhaps"));
											}
											}
```
## 배운점

* 처음으로 테스트 환경설정과 작성을 해봤는데 흥미로웠다. 앞으로 과제할때도 쓸 수 있을 것 같다!

## 반성할 점

* 오늘은 딱히 없었다.
