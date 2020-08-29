class Kata {
  public static String getMiddle(String word) {
   
  int length = word.length();
  int half = length / 2;
  boolean Even = length % 2 == 0;
    
      
    return Even ? word.substring(half - 1, half + 1) :
                  word.substring(half, half + 1);
    
    
  }
}
