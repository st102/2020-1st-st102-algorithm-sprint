# SquareDigits

## 문제 설명

* 입력된 수 각자리수의 제곱을 스트링으로 리턴

## 나의 풀이

```java
public class SquareDigit {

  public int squareDigits(int n) {
    
  String result = "";
  int digit = 0;
  
  if( n < 10 )
    return n * n;
    
  while ( n > 0 ) {
    digit = n % 10;
    result = digit * digit + result;
    n = n / 10;  
  }
  
    return Integer.valueOf(result);
}
  }
```
* 입력된 수를 한 자리씩 분리해서 result 스트링에 붙이고 리턴한다.
* 처음엔 split으로 배열에 넣어서 풀 생각을 했는데 코드가 너무 길어졌다.

## 다른 사람 풀이

```java
import java.util.stream.Collectors;

public class SquareDigit {

    public int squareDigits(int n) {
        return Integer.parseInt(String.valueOf(n)
                                      .chars()
                                      .map(i -> Integer.parseInt(String.valueOf((char) i)))
                                      .map(i -> i * i)
                                      .mapToObj(String::valueOf)
                                      .collect(Collectors.joining("")));
    }

}
```
* 스트림으로 풀이 했다. 읽기 좋고 눈에 딱딱 들어와서 베스트인것 같다. 


## 배운 점

* 잘 몰랐던 스트림에 대해 공부했다.
* vauleOf 와 parseInt 의 차이점에 대해 공부했다. parseInt 는 자료형으로 리턴하고 valueOf 는 new Integer() 객체형으로 리턴한다고 한다.

valueOf() returns an Integer object while Integer.parseInt() returns a primitive int.


## 반성할 점

* 시간을 정해놓고 문제푸는 연습을 해야겠다. 너무 빙빙 돌아서 생각하는 것 같다.
