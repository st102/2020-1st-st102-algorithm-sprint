# Vowel Count

## 문제 설명

*  주어진 정수보다 작은 자연수들중 3과 5의 배수들의 합을 구하라
*  만약 주어진 수가 음수일 경우 0을 반환한다.

## 나의 풀이 방법

```java
public class multiples {

    public static int getMultiples(int num) {
        int multiple_sum = 0;

        if (num <= 0)
            return 0;

        for (int i = 0; i < num; i++) {
            if (i % 3 == 0 || i % 5 == 0)
                multiple_sum += i;
        }
        return multiple_sum;
    }
}
```

*   평소에 자주 접했던 문제라 푸는것이 어렵지 않았다.
*   지난 피드백에서 나온 얘기 중 코드 포맷팅을 일관성 있게 구성하고, 읽기 좋은 코드를 만들기 위한 네이밍 위주로 포커스를 두었다.

## 다른 사람의 풀이 방법

### Best Practice

```java
import java.util.stream.IntStream;

public class Solution {
  public int solution(int number) {
    return IntStream.range(0, number)
                    .filter(n -> (n % 3 == 0) || (n % 5 == 0))
                    .sum();
  }
}
```
*   자바의 스트림을 사용해 불필요한 변수 선언과 조건문 등을 줄여주면서 코드가 훨씬 보기 좋았다.

## 배운 점

*  현재 자바 문법을 공부하면서 스터디를 병행하고 있는데, 확실히 코딩을 하면서 공부하니까 사용 방법에 대해 익숙해졌고, 같은 알고리즘이라도 다양한 문법을 통해 더 간결하게 만들 수 있다고 생각했다.

## 반성할 점

*  자바 문법을 공부했었지만 확실히 얕게 공부했었다고 생각했고, 익숙한 문제더라도 다른 방법으로 풀어보는 습관을 가져야 겠다.
