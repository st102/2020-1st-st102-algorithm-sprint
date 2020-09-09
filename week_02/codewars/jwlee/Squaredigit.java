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
