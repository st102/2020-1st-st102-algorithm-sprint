# Disemvowel Trolls

## 문제 설명

문자열을 입력받아서 모음을 모두 없앤 문자열을 리턴


## 나의 풀이 방법

public class Troll {
    public static String disemvowel(String str) {

      StringBuilder result = new StringBuilder();
      for(char k : str.toCharArray()) {
        switch(k) {
            case 'a' :
            case 'A' :
            case 'e' :
            case 'E' :
            case 'i' :
            case 'I' :
            case 'o' :
            case 'O' :
            case 'u' :
            case 'U' :
            continue;
        }

          result.append(k);
      }

          return result.toString();
    }
}

String 을 입력받아서 for문으로 모음인 경우를 제외하고는 result에 붙여서 문자열로 리턴했다.

If it's not a vowel, append an element of array to result and return a string. 



## 다른 사람의 풀이 방법


public class Troll {
  public static String disemvowel(String str) {
      return str.replaceAll("[aAeEiIoOuU]", "");
  } 
}

replaceAll이라는 함수를 처음보았다. 매우 유용한 것 같다! 


## 배운 점


StringBuilder 와 StringBuffer 에 대해 깊게 공부했다. + 로 문자열을 붙일 수 있지만, 문자열이 길이지거나 수십번 더해지는 경우에는 메모리 관리적 측면에서는 치명적이라고 한다. 앞으로 class를 고를때에도 고민을 더 해보는 습관을 길러야겠다.

if you use + to put Strings together, it will result in the same output. but thty are only equivalent provided that they are not nested or you don't need to concatenate a large number of strings. It can be fatal to memory management. Should make a habit to think about all these things when choose a class.

## 반성할 점


처음에 문자열과 문자배열을 헷갈렸다. 기초적인 곳에서 헷갈려서 자괴감이 들었다. 기초부터 탄탄히 공부해야겠다.


## Action Item


일요일에 이번주 푼 문제들을 꼭 복습하고 내 것으로 만들어야겠다.
