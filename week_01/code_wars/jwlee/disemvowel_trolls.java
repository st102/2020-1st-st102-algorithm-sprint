public class Troll {
    public static String disemvowel(String str) {
        
      StringBuilder result = new StringBuilder();
      int index = 0;
      char[] save = new char[str.length()];
      
      for(char k : str.toCharArray()) {
        switch(k) {
            case 'a' :
            case 'A' :
            case 'e' :
            case 'E' :
            case 'i' :
            case 'I' :
            case 'o' :
            case 'O' :
            case 'u' :
            case 'U' :
            continue;
        }
          save[index++] = k; 
       
        result.append(k);
      }
      
          return String.valueOf(result);
      
         
    }
}
