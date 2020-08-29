public class Troll {
    public static String disemvowel(String str) {
        
      StringBuilder result = new StringBuilder();
      
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
       
        result.append(k);
      }
      
          return result.toString();
      
         
    }
}
