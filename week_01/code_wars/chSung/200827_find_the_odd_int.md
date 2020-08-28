# Find the odd int

## 문제 설명

*   주어진 정수 배열에서 홀수번 나타나는 숫자 찾기 (딱 한 숫자만 홀수번 등장함)

## 나의 풀이 방법

```java
public class FindOdd {
    public static int findIt(int[] a) {

        int i;
        for (i = 0; i < a.length; i++) {
            int num = 0;
            for (int j = 0; j < a.length; j++) {
                if (a[i] == a[j]) num++;
            }
            if (num % 2 != 0) return a[i];
        }

        int odd = a[i];

        return odd;

    }
}
```

*   가장 단순하게 생각했다. 사실 몇 가지 방법이 떠올랐으나 (오름차순 정리, 특정 원소 바꾸기 등) 자바 문법이 떠오르지 않아 이 방법으로 했다. 이중for문이기 때문에 효율적이지 않을 것이다.
*   배열 조작 함수들은 앞으로 많이 쓸꺼기 때문에 이번 코드문제로 공부해 놓자.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class FindOdd {
  public static int findIt(int[] A) {
    int xor = 0;
    for (int i = 0; i < A.length; i++) {
      xor ^= A[i];
    }
    return xor;
  }
}
```

*  이 문제는 XOR 연산을 기억하고 있었다면 매우 깔끔하고 효율적으로 풀었을 것이다... 다룬 문법 자체는 어렵지 않았다.

### Clever

```java
import static java.util.Arrays.stream;

public class FindOdd {
  public static int findIt(int[] arr) {
    return stream(arr).reduce(0, (x, y) -> x ^ y);
  }
}
```

*   마찬가지로 XOR연산을 사용했으나 stream이용해 for문없이 빠르고 깔끔하게 코딩했다.
*   배열의 모든 항목을 XOR연산 시켜서 동일한 숫자의 pair을 서로 제거하여 홀수 번 나타나는 유일한 숫자를 남기는 방식이다. 
*  스트림과 람다식을 알아야하는 내용같다. 솔직히 잘 이해를 하지 못했다... 주말에 이 내용을 더 공부해보겠다 예습도 할겸

## 배운 점

*  배열을 여러가지 방법으로 탐색을 하기위해 for문을 다양한 방법으로 돌려보았다. 나는 기초가 없으니 이런데서 시간을 더 투자해 공부해야한다

## 반성할 점

*   알고리즘 초보인 나에게는 나름 머리를 써야하는 문제였다.. "홀수번 나타나는 단 하나의 숫자를 뽑아내는 것"은 어렵지 않지만 그 방법이 다양하고 또 컴퓨터 언어로 바꾸는 과정이 힘겨웠다 언어를 뭐 하나라도 제대로 알고 있는게 없다보니 문제였다 

## Action Item

*   주말에 주중에 했던 코드를 모두 복습하고 삼항연산자, 람다식, 스트림 다는 못하더라도 공부하기
*   다음 문제도 배열 다루는 것 같으니 다양하게 반복문 써보기
