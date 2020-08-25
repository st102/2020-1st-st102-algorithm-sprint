package week_01.code_wars.cmSon;

public class Vowels {

    public static int getCount(String str) {
      int vowelsCount = 0;
      int length_to_string = str.length();
      
      for (int i = 0; i < str_l; i++){
        char alphabet = str.charAt(i);
        
        if (alphabet == 'a' || alphabet == 'e' || alphabet == 'i' || alphabet == 'o' || alphabet == 'u'){
          vowelsCount++;
        }
      }
      
      return vowelsCount;
    }
  
  }
