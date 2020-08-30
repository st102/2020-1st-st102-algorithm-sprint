# Disemvowel_Trolls

## 문제 설명

*  주어진 단어의 모음을 제외한 문자열을 반환하여라.


## 나의 풀이 방법

```java
public class Disemvowel_Trolls {

    public static String disemvowel(String str) {
        String output = "";

        for (char c: str.toCharArray()) {
            switch (c) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    continue;
            }
            output = output.concat(String.valueOf(c));
        }

        return output;
    }
}
```

*  switch문을 통해 모음들을 거르고, 남은 문자들을 순서대로 concat을 통해 문자열을 완성했다.
*	 제외해야 할 문자들이 많아질수록 코드가 길어진다는 단점이 있다.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class Troll {
  public static String disemvowel(String str) {
      return str.replaceAll("[aAeEiIoOuU]", "");
  }
}
}
```
*   이 방법을 알고 있었지만, 단순히 이렇게만 한다면 무슨 의미가 있을까 싶어서 이 방법은 사용하지는 않았다.
*   하지만 알아두면 확실히 도움이 될 메소드이다.

## 배운 점

*  스터디를 진행하면서, 많은 피드백과 한 문제에 따른 다양한 코드들을 접하다보니 정말 생각하며 코딩하는 습관이 생기는거 같다.

## 반성할 점

*  이 문제를 풀었을 때, concat과 valueOf을 사용해야겠다고 생각했지만, 사용법을 잘 몰라 책을 찾아보느라 시간이 좀 걸렸다.
*  비교적 기본적인 문법이더라도 확실하게 사용법을 익혀야겠다.
