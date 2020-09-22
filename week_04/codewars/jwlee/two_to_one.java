import java.util.*;

public class TwoToOne {

    public static String longest (String s1, String s2) {

      char[] arr = (s1 + s2).toCharArray();
      Arrays.sort(arr);
      ArrayList<Character> charArray = new ArrayList<Character>();

      for(char index : arr) {
        if(!(charArray.contains(index))) {
          charArray.add(index);
        }
      }

      return charArray.toString().replaceAll(", ","").substring(1,charArray.size()+1);

    }
}

