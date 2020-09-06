```java
public class Kata {
  public static String highAndLow(String numbers) {
    String[] split = numbers.split(" ");
    int min, max = Integer.parseInt(split[0]);
    
    String result = "";  
    
    for(int i = 0; i < split.length; i++) {  
      
    if(min > Integer.parseInt(split[i]))
      min = Integer.parseInt(split[i]);
      
    if(max < Integer.parseInt(split[i]))
      max = Integer.parseInt(split[i]);
        
    }
    return max + " " + min;
  }
}
```
