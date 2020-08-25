# Vowel Count

## 문제 설명

*   주어진 문자열에서 모음의 개수를 반환하라.
*   (y를 제외한 a,e,i,o,u 를 모음으로 생각할것이고, 입력 문자열은 소문자 및 공백으로만 구성된다.)

## 나의 풀이 방법

```java

public class Vowels {

  public static int getCount(String str) {
    int vowelsCount = 0;
    
    for (int i = 0; i < str.length(); i++)
      {
      if (str.charAt(i) == 'a' || str.charAt(i) == 'e' || str.charAt(i) == 'i' || str.charAt(i) == 'o' || str.charAt(i) == 'u')
        vowelsCount++;
    }
    return vowelsCount;
  }
}
```

*   모음 5개의 관점에서 문자열에 포함된 모음 갯수를 셀 것인가, 문자열 관점에서 모음 포함 여부를 셀 것인가를 고민했다. 4글자 이하일 때는 글자 하나하나의 모음여부를 체크하는 것이 빠르지만 더 많은 수의 영어단어가 5자 이상이기 때문에 전자의 방법을 택했다.


## 다른 사람의 풀이 방법

### Best Practice

```java

public class Vowels {

    public static int getCount(String str) {
        return str.replaceAll("(?i)[^aeiou]", "").length();
    }

}
```

*   자바 초보자인 나에게는 기괴한 코드였다. 찾아보니 정규식을 이용한 코드이고 모음을 제외한 캐릭터를 싹다 공백으로 바꿔버린 후 남은 문자열의 길이를 이용해 반환하는 방식이였다.
*   지금 당장 정규식을 공부하기에는 벅차 리스펙만 하고 넘어가기로 했다.

### Others

```java

public class Vowels {

  public static int getCount(String str) {
    int vowelsCount = 0;
    for(int i = 0; i < str.length(); i++) {
        switch(str.charAt(i)) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            vowelsCount++;
        }
    }
    return vowelsCount;
  }

}
```

*   정규식을 사용하지 않으면 case문이 베스트인 것 같다. 스위치-케이스문을 사용해 내 코드보다 깔끔하다.


## 배운 점

*   정규식을 몰라도 저런 아이디어는 대단한 것 같다. 근데 저런 발상도 정확한 언어문법이나 기능들을 잘 알고 있어야만 나올 것이다 이번학기에 자바 문법과 기초를 튼튼히 할 것이다
*   조건,반복문을 사용할 때는 어떤 문법이 효율적인지 생각해 봐야겠다.

## 반성할 점

*   사실 언어 하나도 제대로 못하면서 알고리즘을 풀려는게 부끄럽다. 처음 푸는 알고리즘이니까 언어 자체와 병행해서 공부해야겠다.


## Action Item

*   내 수준에서 풀 만한 문제였지만 슬슬 알고리즘 이론이나 모르는 문법이 나올 것 같다. 시간을 좀 더 투자해서 공부해보자
