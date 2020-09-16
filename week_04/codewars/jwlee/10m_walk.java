public class TenMinWalk {
  public static boolean isValid(char[] walk) {
    
    int x = 0, y = 0;
    
    if(walk.length != 10) {
      return false;
    }
    
    for(char a : walk) {
      switch(a) {
        case 'e' : x++; break;
        case 'w' : x--; break;
        case 's' : y++; break;
        case 'n' : y--; break;  
      }
    }
    
    if(x == 0 && y == 0)
      return true;
    
    return false;
  }
}
