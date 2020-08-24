# Vowel Count

## 문제 설명

주어진 string 내의 모음 개수를 계산한다

## 나의 풀이 방법

```java
public class Vowel {

	public static int get_count(String str)
	{
		int count=0;
		char[] chr = str.toCharArray();

		for(char e : chr)
		{
			switch(e)
			{
			case 'a' :
			case 'e' :
			case 'i' :
			case 'o' :
			case 'u' :
				count++;
			}
		}
		return count;
	}

}
```

*   toCharArray() 메소드를 사용해 문자열을 char형 배열에 넣고 향상된 for문을 사용해 배열의 요소를 비교하는 방법으로 풀었다.
*   테스트는 empty_string 일 때, vowel 이 없을 때, vowel 만 이루어졌을 때로 나누었다.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class Vowels {

  public static int getCount(String str) {
    int vowelsCount = 0;

    for(char c : str.toCharArray())
      vowelsCount += (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') ? 1 : 0;

    return vowelsCount;
  }

}
```
*   다른 좋은 풀이도 많았지만 내 코드에서 한줄이라도 더 줄여 간결하게 만들었다고 생각한다.
*   문자열을 배열에 넣는 과정도 for문에 넣으면서 간결해졌고, 당연히 if문이나 switch문을 사용해야 된다고 생각했지만 조건연산자를 활용했다는 점이 신선했다.

## 배운 점

*  코드를 더 간결하게 만들기 위해 다양한 문법과 메소드들을 찾아가며 활용하면서 사용방법에 대해 익숙해졌다.

## 반성할 점

*  문제를 보자마자 직관적으로 코드를 치는것이 아닌, 먼저 생각을 하는 습관을 들여야 할 것 같다.
