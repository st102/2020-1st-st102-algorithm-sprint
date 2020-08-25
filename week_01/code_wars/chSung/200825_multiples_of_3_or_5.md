# Multiples of 3 or 5 

## 문제 설명

*   주어진 숫자 미만의 자연수 중 3 or 5 의 배수 값들의 합을 구한다

## 나의 풀이 방법

```java
public class Solution {

    public int solution(int number) {
        int sum = 0;

        for (int i = 1; i * 3 < number; i++) {
            sum += i * 3;
        }
        for (int i = 1; i * 5 < number; i++) {
            if ((i * 5) % 15 == 0) {
                continue;
            }
            sum += i * 5;
        }

        return sum;
    }
}
```

*   수학자체는 쉬운문제라서 나름 효율을 생각해보았다
*   먼저 계산과정에서 3,5의 배수판정법을 쓰면 아주 큰 수에게는 도움이 될 것 같았다. (컴퓨터가 나머지 계산을 어떻게 하는지는 찾아봐야겠다) 일반적인 수는 별 차이가 없을 것 같아 수 자체를 탐색하는 범위를 줄여야겠다고 생각했다
*   나누어 떨어지는 개념이 아니라 그냥 단순히 3,5의 배수를 쭉 저장하기로 했다 물론 15의 배수 처리는 해줘야한다

## 다른 사람의 풀이 방법

### Best Practice

```java
public class Solution {

  public int solution(int number) {
    int sum=0;
    
    for (int i=0; i < number; i++){
      if (i%3==0 || i%5==0){sum+=i;}
    }
    return sum;
  }
}
```

*   사실 이게 왜 베스트인지 모르겠다... 1부터 주어진 숫자까지 모든 영역을 볼 필요가 없는데
*   뭔가 내가 잘못생각하고 있는게 있을지도 모른다


###Clever

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

*   잘 몰라서 찾아보았는데 자바8부터 추가된 IntStream을 이용한 것이였다
*   원시데이터형 int를 스트림으로 다룰 수 있게 해준다. intStream을 range 함수로 생성하고 filter함수로 조건을 걸고 합해준다.
*  intStream의 Iterator, allMatch 함수도 한번 연습해봤다

## 배운 점

*  피드백 받은 컨벤션 코드를 적용했다. 보기 깔끔하다
*  자세히는 아니지만 자바에 대한 추가적인 공부를 했다(intStream)

## 반성할 점

*   문제에 있던 조건중에 0또는 음수의 경우 0을 리턴하라했는데 까먹고 제출했었다.. 근데 솔루션들에도 전부 빼먹어놔서 당황스럽다!

## Action Item

*   컨벤션코드 적용하기는 꾸준히 하고, 효율성 측면에서 오늘 내 코드가 맞는건지 피드백을 받고나서 다음 코딩에 적용해야겠다.
