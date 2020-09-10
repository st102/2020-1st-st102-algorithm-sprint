# Stop gninnipS My sdroW!

## 문제 설명

*  

## 나의 풀이 방법

```java
package Cote_Package;

public class Reverse_Word {
	public String spinWords(String sentence) {
	    StringBuffer strbuf = new StringBuffer();
	    String[] wordarr = sentence.split(" ");
	    String output="";
	    for(String word : wordarr){
	      if(word.length() > 4){
	        output += strbuf.append(word).reverse().toString() + " ";
	        strbuf.setLength(0);
	      }

	      else
	        output += word + " ";
	    }
	    return output.substring(0,output.length()-1);
	  }
}
```

*  5글자 이상되는 단어를 거꾸로 만들기 위해서 StringBuffer를 사용하였다.
*  문제 자체는 어렵지 않았지만, StringBuffer를 비워주지 않는 실수를 해서 시간을 오래 쓰게 되었다.


## 테스트 코드
```java
package Cote_Package;
import org.junit.Test;
import static org.junit.Assert.assertEquals;

public class Test_Reverse {
	@Test
    public void test() {
      assertEquals("12345", new Reverse_Word().spinWords("54321"));
      assertEquals("1 12 123 1234 12345", new Reverse_Word().spinWords("1 12 123 1234 54321"));
      assertEquals("12345 654321 123", new Reverse_Word().spinWords("54321 123456 123"));
    }
}
```
*  5글자 이상인 단어 하나만 있을때, 여러 단어 중 5글자 이상인 단어 하나만 있을 때, 여러 단어중 5글자 이상인 단어가 둘일 때를 테스트하였다.


## 다른 사람의 풀이 방법

### Best Practice

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
*   내 코드랑 비슷하지만 문자열에 하나씩 단어를 추가하는것이 아닌, 배열에 재구성 후 join함수를 통해 문자열을 바꾸면서 코드가 훨씬 간결해졌다.


## 배운 점

*  join함수에 대해 알고는 있었지만, 직접 사용해본적은 없었는데 이번에 사용 예시를 보면서 자세히 알게되었다.


## 반성할 점

*  코드를 줄일 생각과 다양한 문법을 사용하려고만 생각하다보니 정작 중요한 부분에서 실수하는게 생긴다.
*  앞으로는 이런 실수에 대해서 미리 생각하여 줄이는 습관을 들여야겠다.
