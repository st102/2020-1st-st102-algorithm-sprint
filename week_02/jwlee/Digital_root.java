public class DRoot {
  public static int digital_root(int n) {
    
      
      int sum = 0;
      
    while(n >= 10) {
       sum += n % 10;  
       n /= 10;
    }
      sum += n;
      
    return sum >= 10 ? digital_root(sum) : sum;
   
}
  }
