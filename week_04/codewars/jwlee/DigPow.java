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
