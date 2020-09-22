# Equal Sides Of An Array

## 문제 설명

*  

## 나의 풀이 방법

```java
package Cote_Package;
import java.util.stream.IntStream;
public class Equal_Sides {
    public static int findEvenIndex(int[] arr) {
        int left = 0;
        int right = IntStream.of(arr).sum();

        for (int i = 0; i < arr.length; i++) {
            right -= arr[i];

            if (left == right)
                return i;

            left += arr[i];
        }
        return -1;
    }
}
```

*  스트림을 이용해 배열의 모든 수들을 더해 변수에 저장하고, for문을 통해 증가와 감소를 통해 비교하였다.


## 다른 사람의 풀이 방법

### Best Practice

```java
import java.util.Arrays;

public class Kata {
  public static int findEvenIndex(int[] arr) {
    int left = 0;
    int right = Arrays.stream(arr).sum();
    for (int i=0; i<arr.length; i++){
      right -= arr[i];
      if (left == right) return i;
      left += arr[i];
    }
    return -1;
  }
}
```
*   나와 알고리즘이 아예 똑같다.
*   스트림 부분에서 나와 다른점이 있는데 이 부분에 대해서 찾아봤지만 분명한 차이점은 제대로 찾지 못했다.


## 배운 점

*  자바 공부를 하면서 스트림에 어느 정도 알았다고 생각했지만, 아직 더 배워야 한다고 느꼈다.


## 반성할 점

*  지난주에는 학교수업과 학원수업 진도를 맞추느라 스터디를 하지 못했는데
*  이번주부터라도 할 수 있는 날은 최대한 해야겠다.
