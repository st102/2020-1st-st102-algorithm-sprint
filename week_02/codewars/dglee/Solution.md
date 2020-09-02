# Disemvowel_Trolls

## 문제 설명

*  

## 나의 풀이 방법

```java
public class Solution {
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

*  불필요한 변수 선언을 줄이고, 코드를 간결하게 하기 위해 각 case에서 반환할 때, 코드를 작성했다.
*  문자열을 합치는 방법으로 처음에는 concat을 사용하려 했으나, +연산자를 사용했을 때, 코드가 보기가 좋아 +연산자를 사용하게되었다.

## 다른 사람의 풀이 방법

### Best Practice

```java
class Solution {
    public static String whoLikesIt(String... nms) {
        switch (nms.length) {
          case 0: return "no one likes this";
          case 1: return String.format("%s likes this", nms[0]);
          case 2: return String.format("%s and %s like this", nms[0], nms[1]);
          case 3: return String.format("%s, %s and %s like this", nms[0], nms[1], nms[2]);
          default: return String.format("%s, %s and %d others like this", nms[0], nms[1], nms.length - 2);
        }
    }
}
```
*   case문을 사용한것은 나와 같지만 String 메소드 중 format 메소드를 사용하여 문자열을 합쳤다.
*   확실히 이 메소드를 사용하게 되면, 긴 문장의 경우에는 +연산자를 사용하는것보다 더 정확하고 짧게 만들 수 있을것 같다.

## 배운 점

*  이번 문제를 통해 다양한 String 메소드들을 찾아보게 되었고, 여기 나온 메소드 뿐만 아니라 몰랐던 메소드들도 접하게 된 좋은 계기가 되었다.


## 반성할 점

*  코드워즈에서 직접 코딩하면 오류가 날 경우 문제를 잘 찾지못해 오래걸리는 경우가 있는데 스스로 이클립스에서 테스트 코드를 만드는것도 습관화 해야겠다.
