# Two to One

## 문제 설명
* 두가지 스트링을 합쳐서 중복되는 것을 제외하고 리턴해라

## 나의 풀이
```java
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
```
* 일단 두개의 스트링을 합쳤다. 그리고 chararray 로 바꾼다음 알파벳순으로 정렬하고, arraylist 를 하나 새로만들어서 arr 을 돌면서 list 에 그 알파벳이 있으면 add 하는 방식으로 중복을 filtering 했다. 그 list 에서 ,와 []을 빼고 string으로 리턴한다. 

## 다른 사람 풀이
```java
public class TwoToOne {
    
     public static String longest (String s1, String s2) {
        StringBuilder sb = new StringBuilder();
        (s1 + s2).chars().distinct().sorted().forEach(c -> sb.append((char) c));
        return sb.toString();
    }
}
```
* 합쳐서 중복제거하고 정렬한다음 sb로 리턴.
```java
import java.util.stream.*;

public class TwoToOne {
    
    public static String longest (String s1, String s2) {
        return Stream.of(s1.concat(s2).split(""))
                  .sorted()
                  .distinct()
                  .collect(Collectors.joining());
    }
}
```
* 비슷하다. 

## 배운 점
* 스트림으로 중복제거하는 방법

## 반성할 점
* 학기가 시작되니까 알고리즘 공부에 소홀해지게 된다. 
* 나는 바보다...
