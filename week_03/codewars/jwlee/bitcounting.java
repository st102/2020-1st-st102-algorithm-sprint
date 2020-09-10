public class BitCounting {

  public static int countBits(int n){
    
    return Integer.toBinaryString(n).replaceAll("0","").length();
  }
  
}
