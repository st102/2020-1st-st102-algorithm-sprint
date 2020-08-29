# Disemvowel Trolls

## 문제 설명

*  문자열을 받고 모음이 제거된 새로운 문자열을 반환하라.

## 나의 풀이 방법

```java
public class Troll {
    public static String disemvowel(String str) {
        return str.replaceAll("[AEIOUaeiou]", ""); 
    }
}
```

*   바로 어제 문제와 관련해 문자열을 다루는 함수 몇개를 공부했는데 그 중 replaceAll() 메소드도 있었다.  그래서 편하게 한줄짜리 코딩을 할 수 있었다.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class Troll {
    public static String disemvowel(String Z) {
        return Z.replaceAll("(?i)[aeiou]" , "");
    }
}
```

*  우선 변수명을 Z로 해서 -1점 감점했다
*  (?i) 는 정규식에서 쓰는 옵션이고 앞에 넣어주면 대소문자를 구분하지 않는다.

### Others

```java
public class Troll {
    public static String disemvowel(String str) {
      String output = "";
      for (int i=0; i<str.length(); i++) {
        switch (str.toLowerCase().charAt(i)) {
          case 'a': output+= "";
            break;
          case 'e': output+= "";
            break;
          case 'i': output+= "";
            break;
          case 'o': output+= "";
            break;
          case 'u': output+= "";
            break;
          default: output+= str.charAt(i);
        }
      }
      return output;
    }
}
```

*   이번엔 Clever 풀이 보다 단순무식풀이로 한번 적어보았다.

## 배운 점

*  어제 문자열 관련 메소드를 공부한 보람이 있다.
*  정규식 중 전부는 아니지만 ^ $ {} \ 정도의 의미를 공부했다.

## 반성할 점

*  이번 내용에서는 딱히 없다.

## Action Item

*   다음주 문제풀이 전에 내일은 주간에 했던 문제 복습을 하고 적어두었던 자바 문법 내용을 학습할 것이다.
