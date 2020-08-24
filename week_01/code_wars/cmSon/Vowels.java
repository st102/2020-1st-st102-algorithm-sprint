package week_01.code_wars.cmSon;

public class Vowels {

    public static int getCount(String str) {
      int vowelsCount = 0;
      // your code here
      int str_l = str.length();
      
      for (int i = 0; i < str_l; i++){
        char c_temp = str.charAt(i);
        
        if (c_temp == 'a' || c_temp == 'e' || c_temp == 'i' || c_temp == 'o' || c_temp == 'u'){
          vowelsCount++;
        }
      }
      
      return vowelsCount;
    }
  
  }