# Who likes it?

## 문제 설명

* 입력된 이름에 맞게 리턴한다. 

## 나의 풀이 방법

```java
class Solution {
    public static String whoLikesIt(String... names) {

    int length = names.length;
    switch(length) {
        case 0 : return "no one likes this";
        case 1 : return names[0] + " likes this";
        case 2 : return names[0] + " and " + names[1] + " like this";
        case 3 : return names[0] + ", " + names[1] + " and " + names[2] + " like this";
        default : return names[0] + ", " + names[1] + " and " + (length - 2) + " others like this";
    }
      }
  }
```  

* 처음엔 저번 문제에서 배웠던 것들을 활용해 보려고 했으나 너무 코드가 길어질 것 같아서 + 로 문자열을 더했다. 


## 다른 사람의 풀이 방법
### Best Practice

```java

class Solution {
    public static String whoLikesIt(String... names) {
        switch (names.length) {
          case 0: return "no one likes this";
          case 1: return String.format("%s likes this", names[0]);
          case 2: return String.format("%s and %s like this", names[0], names[1]);
          case 3: return String.format("%s, %s and %s like this", names[0], names[1], names[2]);
          default: return String.format("%s, %s and %d others like this", names[0], names[1], names.length - 2);
        }
    }
}
```
String format에 대하여 알게 되었다! 만약 붙이는 문자열의 길이가 길어야 한다면 유용할 것 같다.
got to know about String format! I would be useful when I have to add a long string to the other one, 

## 배운 점

String 메소드는 파도파도 계속 나온다. 계속 쓰면서 익숙해지게 해야겠다.


## 반성할 점

어떻게 풀어야 간단할지 먼저 생각해보고 시작해야겠다. 처음부터 StringBuilder 로 하려고 했다가 다 지우고 다시했다. 
