# Vowel Count

## 문제 설명

*   주어진 string 내의 모음 개수를 계산한다

## 나의 풀이 방법

### 문제 풀이 코드
```java
public class Vowels {

  public static int getCount(String str) {
    int vowelsCount = 0;
    int str_l = str.length();
    
    for (int i = 0; i < str_l; i++){
      char c_temp = str.charAt(i);
      
      if (c_temp == 'a' || c_temp == 'e' || c_temp == 'i' || c_temp == 'o' || c_temp == 'u'){
        vowelsCount++;
      }
    }
    
    return vowelsCount;
  }

}

```

### 테스트 코드
```java
import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class VowelsTest {
    @Test
    public void testCase_vowelsCount_5() {
      assertEquals("Nope!", 5, Vowels.getCount("abracadabra"));
    }
    
    @Test
    public void testCase_vowelsCount_0() {
      assertEquals("Nope!", 0, Vowels.getCount("pplqwzz"));
    }
  
    @Test
    public void testCase_string_empty() {
      assertEquals("Nope!", 0, Vowels.getCount(""));
    }
}
```

*   문자열의 한글자씩을 일일이 가져와 for문을 통해 비교하는 방법으로 문제를 풀이하였다
*   테스트는 empty_string 일 때, vowel 이 없을 때, vowel 만 이루어졌을 때로 나누었다, codewars 에서 제공해주는 test 코드를 응용하였다.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class Vowels {

  public static int getCount(String str) {
    int vowelsCount = 0;
   for(int i=0; i< str.length(); i++)
        {
            if("AEIOUaeiou".contains(str.subSequence(i,i+1)))
            {
                vowelsCount++;
            }
        }

    return vowelsCount;
  }

}
```

* 내 생각에는 이게 베스트인거 같다.
* contains를 이용하여 풀이는 많았는데 유일하게 이사람만 대문자만 생각해준거 같다.

### Others

```java
public class Vowels {

    public static int getCount(String str) {
        return str.replaceAll("(?i)[^aeiou]", "").length();
    }

}
```

*  정규식을 이용하여 풀이하였다 상상도 못한 풀이 방법이었다, 아직 정규식에 익숙하지않아서 조금더 공부해봐야겠다.
*  정규식을 이용하여 a,e,i,o,u 문자만 제외한 나머지 문자를 공백으로 변경한후 남은 문자열의 길이를 반환하는 방식이다.

### Others2

```java
public class Vowels {

  public static int getCount(String str) {
    int vowelsCount = 0;
    for (int i = 0 ; i < str.length() ; ++i)
    {
      switch (str.charAt(i))
      {
        case 'a': case 'e': case 'i': case 'o': case 'u': ++vowelsCount; break;
      }
    }
    // your code here
    return vowelsCount;
  }

}
```

*  많은 사람이 풀이한 방법이다. 비슷한 방법이지만 case문을 이용하니 보기 더 편한거 같다.

## 배운 점

*  codewars에서 제공해주는 testcode(?)를 이용하여 첨으로 testcode를 작성해보았다. 이 방법이 맞는지는 모르지만 더 공부해야할거 같다.

## 반성할 점

*  처음 공부해보는 코테 문제였는데 문제를 풀이할때 나처럼 if문을 사용하여 조건을 나열한 사람은 찾아보기 힘들었던거 같다. 이 방법은 지향하는 방법이 아닌거 같다.
*  쉬운문제라 단순하게 생각하고 풀이하였는데 담부터는 더 좋은 방법이 있는지 찾는 습관을 가져야 하겠다

## Action Item

*  쉬운 문제일 수록, 좀 더 고민해서, 더 파이써닉 하게 풀 수 있는 방법으로 리팩토링 해서 풀자
*  이 말이 정답인거 같다. 담부터는 더 고민하는 습관을 가져야겠다.