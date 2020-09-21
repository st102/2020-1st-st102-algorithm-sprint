# Tribonacci Sequence

## 문제 설명
피보나치와 원리는 똑같은데 3개

## 나의 풀이
```java
public class Xbonacci {

  public double[] tribonacci(double[] s, int n) {

    double[] result = new double[n];
    
    for(int i = 0 ; i < n; i++) {
     result[i] = i<3? s[i]:result[i-1] + result[i-2] + result[i-3];
    }
    
    
     return result;

  }
}
```

## 다른 사람 풀이
```java
import java.util.Arrays;
import java.util.stream.Stream;

public class Xbonacci {

    public double[] tribonacci(double[] start, int n) {
        return Stream.iterate(start, tuple -> applySequenceRule(tuple))
            .mapToDouble(tuple -> tuple[0])
            .limit(n)
            .toArray();
    }
    
    private double[] applySequenceRule(double[] tuple) {
        return new double[]{tuple[1], tuple[2], tuple[0]+tuple[1]+tuple[2]};
    }
  
}
```
* 스트림으로 푼 사람도 있다.
```java
import java.util.Arrays;

public class Xbonacci {
  public double[] tribonacci(double[] s, int n) {

      double[] tritab=Arrays.copyOf(s, n);
      for(int i=3;i<n;i++){
        tritab[i]=tritab[i-1]+tritab[i-2]+tritab[i-3];
      }
      return tritab;

    }
}
```
* 배열을 복사해서 만든다. 좋은 것 같다!

## 배운 점
* 피보나치에 대해서 다시 볼 수 있었다! 

## 반성할 점
* 머리가 많이 굳은 것 같다. 매일 풀면서 익숙해져야겠다. 
