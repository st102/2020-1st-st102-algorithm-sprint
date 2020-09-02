# Who likes it

## 문제 설명

*  입력받는 스트링에 따라 예시처럼 출력하라 (예시는 어떻게 출력하는지 설명되어있음)

## 나의 풀이 방법

```java
class Solution {
    public static String whoLikesIt(String...names) {
        switch (names.length) {
            case 0:
                return "no one likes this";
            case 1:
                return names[0] + " likes this";
            case 2:
                return names[0] + " and " + names[1] + " like this";
            case 3:
                return names[0] + ", " + names[1] + " and " + names[2] + " like this";
            default:
                return names[0] + ", " + names[1] + " and " + (names.length - 2) + " others like this";
        }
    }
}
```

*   if문을 써서 풀고있었는데 이전에 반성할 점에서 case문이 효율적일 경우 써보겠다 한적이 있었다. 가짓수가 3-4가지 밖에 되지 않아서 switch - case 문이 더 좋을 것 같았다
*  스트링으로 그대로 출력하면 돼서 쉬운 문제였다.



## 다른 사람의 풀이 방법

* ### Best Practice / Clever

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

*  switch-case 문을 쓴 점은 똑같지만 return 출력 부분에서 이 코딩이 더 깔끔하고 용이하다. 나처럼 하면 코딩할 때 번거롭다 그리고 잔실수도 잦게 되어 test 할 때 4번은 시도했다
*  string format 형식을 알아두자 : 
String 클래스의 format 메소드는 지정된 위치에 값을 대입해서 문자열을 만들어 내는 용도이다. 
형식 -> %[argument_index$][flags][width]conversion
*  이 문제는 이 이상의 다른 풀이는 필요 없는 듯 하다.


## 배운 점

*  매우 유용한 format 사용법을 배움. 기본포멧에서 다른 옵션들도 한번 써 보았다.

## 반성할 점

*   꼼꼼함이 부족한지 문자열 출력에서 오류가 많이났다.. 띄어쓰기 안하거나 뭐 하나 빼먹거나...

## Action Item

*   이제 string 다루는 기능들은 익숙해지고 있는것 같다. 자바 강의 개강했으니까 아주 세세하게 공부하자

