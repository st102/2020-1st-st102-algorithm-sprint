# Disemvowel_Trolls

## 문제 설명

*  

## 나의 풀이 방법

```java
package Cote_Package;

public class Shortest_Word {
    public static int findShort(String s) {
        String[] array = s.split(" ");
        int short_length = array[0].length();

        for (int i = 1; i < array.length; i++)
            short_length = (array[i].length() > short_length) ? short_length : array[i].length();

        return short_length;
    }
}
```

*  split을 통해 단어 단위로 분리해 배열에 넣은 후 각 단어들끼리 순서대로 길이를 비교하였다.


## 테스트 코드
```java
package Cote_Package;
import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class Short_Test {
	@Test
    public void findShort() throws Exception {
        assertEquals(3, Shortest_Word.findShort("bitcoin take over the world maybe who knows perhaps"));
        assertEquals(3, Shortest_Word.findShort("turns out random test cases are easier than writing out basic ones"));
    }
}
```
*  코드워즈의 테스트코드를 사용하였다.
*  자바를 사용한 TDD를 어떻게 짜야할지 잘 모르겠다.(ex:실패하는 단위 테스트 작성)


## 다른 사람의 풀이 방법

### Best Practice

```java
import java.util.Arrays;

public class Kata {
    public static int findShort(String s) {
        return Arrays.stream(s.split(" ")).mapToInt(String::length).min().getAsInt();
    }
}
```
*   스트림을 사용하면서 불필요한 변수선언과 반복문을 줄였다.


## 배운 점

*  처음에는 스트림 문법에 대해 잘 몰랐지만 지금은 다른 사람의 코드를 봤을 때, 익숙해져서 바로 이해가 된다.


## 반성할 점

*  테스트 코드를 짜보려고 했지만 이해력과 다양한 능력이 딸리는거같다. 자바문법을 사용하는 분(성치훈 형)의 PR만 기다리는 내가 밉다...
