# Spin Words

## 문제 설명
5개 이상 길이의 스트링은 거꾸로 출력하는 전체 스트링 반환

## 나의 풀이
```java
public class SpinWords {

  public String spinWords(String sentence) {

    StringBuilder sb = new StringBuilder();

    for(String a : sentence.split(" ")) {
      if(a.length() > 4) {
        StringBuilder sb2 = new StringBuilder(a);
        sb2.reverse();
        sb.append(sb2);
      }
      else
        sb.append(a);
      sb.append(" ");
    }

    return sb.toString().substring(0, sentence.length());
  }
}

```
* reverse 하는 가장 좋은 방법은 stringbuilder를 이용하는 것 같아서 썼다. 하지만 값을 따로 저장할 stringbuilder 가 하나 더 필요했고 딱히 다른 방법이 떠오르지 않았다. 

## 다른 사람 풀이
```java
import java.util.Arrays;

public class SpinWords {

  public String spinWords(String sentence) {
    String[] words = sentence.split(" ");
    for (int i=0; i<words.length; i++) {
      if (words[i].length() >= 5) {
        words[i] = new StringBuilder(words[i]).reverse().toString();
      }
    }
    return String.join(" ",words);
  }
}
```
* 나와 알고리즘은 같은데 나는 for each 문을 썼지만 이 사람은 그냥 배열에 접근해서 배열 값을 바꿔줬다. 이게 더 짧게 나오는구나... 필요한 상황에 맞게 로직을 잘 쓰자!

```java
public class SpinWords {

  public String spinWords(String sentence) {
        
       for (String a : sentence.split(" "))
       {
           if (a.length()> 4)
           {
              sentence = sentence.replace(a, new  StringBuffer(a).reverse());
           }
       }
       return sentence;
  }
}
```
* replace 메소드를 이용해서 sentence 값을 바꿔주었다. 배열에 넣는 방법 말고도 있구나..

```java
import java.util.stream.*;
import java.util.Arrays;

public class SpinWords {

  public String spinWords(String sentence) {
    return Arrays.stream(sentence.split(" "))
                 .map(i -> i.length() > 4 ? new StringBuilder(i).reverse().toString() : i)
                 .collect(Collectors.joining(" "));
  }
}
```
* 스트림으로 풀려다가 조건문을 어떻게 넣어야 할지 몰라서 포기했는데 이제 알았다!!

## 테스트 코드
```java
package algo.test;

import static org.junit.jupiter.api.Assertions.*;

import org.junit.jupiter.api.Test;

import algo.algo;

class algotest {

	@Test
	void testFindShort() {
		algo Al = new algo();
		
		assertEquals("emocleW", new SpinWords().spinWords("Welcome"));
	    assertEquals("Hey wollef sroirraw", new SpinWords().spinWords("Hey fellow warriors"));
	}

}
```
* 잘 작동하는 것을 확인했다!

## 배운 점

* 스트림에서 조건문 넣는 법을 알았다.

## 반성할 점

* 아직 적재적소에 맞는 메소드를 생각해 내지 못하는 것 같다. 더 열심히 공부하기.
* String 문제만 나오면 builder 를 만들어서 갖다 붙이려고 하는 습관이 있는 것 같다. 
