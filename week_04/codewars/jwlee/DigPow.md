# Playing with Digits

## 문제 설명
조건에 맞춰 수를 반환하라. 

## 나의 풀이
```java
import java.lang.Math;

public class DigPow {
  
  public static long digPow(int n, int p) {
    
    char[] arr = String.valueOf(n).toCharArray();
    int result = 0;
    
    for(int i = 0; i < arr.length; i++) 
       result += Math.pow(Character.getNumericValue(arr[i]), p+i);
    
    return result % n == 0 ? result / n : -1;
  }
  
}
```
* 수를 chararray 에 넣고 제곱한다음 리턴한다. 

## 다른 사람 풀이
```java
public class DigPow {
  
  public static long digPow(int n, int p) {
    String intString = String.valueOf(n);
    long sum = 0;
    for (int i = 0; i < intString.length(); ++i, ++p)
      sum += Math.pow(Character.getNumericValue(intString.charAt(i)), p);
    return (sum % n == 0) ? sum / n : -1;
  }
  
}
```
* 나는 char 배열로 했지만 이 사람은 string 을 이용했다.

## 배운점

* 형변환은 언제해도 헷갈린다. 이 참에 정리가 되었다. 

## 반성할 점

* 오늘은 딱히 없었다. 
