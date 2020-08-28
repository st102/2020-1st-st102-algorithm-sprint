# Get the middle character

## 문제 설명

*   주어진 단어를 받고 가운데에 위치한 문자를 반환하라. 문자가 짝수개인 경우 가운데 두 문자를 반환하라

## 나의 풀이 방법

```java
class Kata {
    public static String getMiddle(String word) {
        String middle_c;
        int length = word.length();

        if (length % 2 == 1) {
            middle_c = String.valueOf(word.charAt(length / 2));
        } else {
            middle_c = String.valueOf(word.charAt(length / 2 - 1));
            middle_c += String.valueOf(word.charAt(length / 2));
        }

        return middle_c;

    }
}
```

*   최대한 내가 아는 문법으로 풀어보려했지만(사실 거의 없다) 이건 구글링이 필요했다... 먼저 문자열에서 원하는 위치의 문자를 찾기 위한 charAt() 메소드와 문자->문자열로 형변환을 시켜주는 String.valueOf() 메소드였다.
*   구현하는 방법만 알면 문제 자체는 간단한 문제였다. 

## 다른 사람의 풀이 방법

### Best Practice

```java
class Kata {
  public static String getMiddle(String word) {
    String s = "";
    int length = word.length();
    int half = length/2;

    if (length % 2 == 0) {
      
      s = word.substring(half - 1, half + 1);
      
    } else {
      
      s = word.substring(half, half + 1);
    
    }
    
    return s;
  }
}
```

*  내 코드와 다른점은 half 라는 변수를 둬서 length/2 의 반복을 썼고 substring 이라는 메소드를 사용하였다 구동방식은 동일하다
*  문자열.substring(시작, 끝) 메소드는 시작, 끝 인덱스를 정해서 잘라주는 메소드이다. 

### Clever

```java
class Kata {
    public static String getMiddle(String word) {
        int length = word.length();
        return (length % 2 != 0) ?  String.valueOf(word.charAt(length / 2)) : word.substring(length / 2 - 1, length / 2 + 1);
    }
}
```

*   동일한 방식이고 삼항 연산자를 이용했다. 이제 이 형식은 익숙해졌다

## 배운 점

*  유용한 도구처럼 바로바로 쓰려면 기본 메소드들은 잘 알고있어야 할 것 같다. 문자열 관련 메소드들 몇개를 더 찾아봤다

## 반성할 점

*  이번 내용에서는 딱히 없다.

## Action Item

*   꾸준히 문법공부와 알고리즘 풀이를 병행할 것
