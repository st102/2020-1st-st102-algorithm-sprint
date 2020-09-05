# Mumbling

## 문제 설명

* accum("abcd") -> "A-Bb-Ccc-Dddd"
accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
accum("cwAt") -> "C-Ww-Aaa-Tttt" 형태를 리턴하는 함수 작성

## 나의 풀이
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
* 일단 쪼개서 배열에 넣은 뒤, 이중 반복문을 통해 출력되도록 했다. 마지막은 - 를 뺴줘야해서 빼줬다.

## 다른 사람 풀이
```java
public class Accumul {
  public static String accum(String s) {
    StringBuilder bldr = new StringBuilder();
    int i = 0;
    for(char c : s.toCharArray()) {
      if(i > 0) bldr.append('-');
      bldr.append(Character.toUpperCase(c));
      for(int j = 0; j < i; j++) bldr.append(Character.toLowerCase(c));
      i++;
    }
    return bldr.toString();
  }
}
```
* char 가 s를 반복하면서 대문자, 소문자를 반복해서 붙인다. 내 코드와 알고리즘은 같은데 for( : ) 문을 쓰니까 훨씬 깔끔해 보인다. 

```java
public class Accumul {

    public static String accum(String s) {
        String result = "";
        for(int i = 0; i != s.length(); i++)
        {
            for(int j = 1; j != i+2; j++)
                result = result + (j == 1 ? s.toUpperCase().charAt(i) : s.toLowerCase().charAt(i));
            result = result + (i != s.length()-1 ? '-' : "");
        }
        return result;
    }
}
```
* 나와 같은 알고리즘. 가독성이 떨어져서 내꺼가 더 나은 거 같다.

## 배운 점

* 처음엔 스트림을 써야하나 뭘 어쨰야하나 고민했지만 단순하게 푸는게 베스트였다. 문제를 단순화하고 효율적이게 푸는 방법이 있는지 고민하기.

## 반성할 점

* 머리회전을 빨리해보자.
