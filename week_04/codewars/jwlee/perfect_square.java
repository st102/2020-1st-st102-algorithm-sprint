import java.lang.*;

public class NumberFun {
  public static long findNextSquare(long sq) {
      
    double a = Math.sqrt(sq);
    
    return (a % 1 == 0)? (long)Math.pow(a+1,2) : -1;
  
  }
}
