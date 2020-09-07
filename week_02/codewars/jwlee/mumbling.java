```java
public class Accumul {
    
    public static String accum(String s) {
    String result = "";
    String[] arr = s.split(""); 
    
    for(int i = 0; i < arr.length; i++) {
      result += arr[i].toUpperCase();
      for(int j = 0; j < i; j++) {
       result += arr[i].toLowerCase();
     } 
      result += "-";
    }
      
    result = result.substring(0, result.length()-1);
  
    return result;
    }
}
```

