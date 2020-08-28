# Vowel Count

## 문제 설명

*  주어진 단어의 가운데 문자를 출력한다. (단어의 길이가 짝수이면 가운데 2개를, 홀수이면 하나를 출력한다.)


## 나의 풀이 방법

```java
public class Middle_Character {
	public static String getMiddle(String word){
		int length = word.length();
		int half = length/2;

		if(length%2==0)
			return word.substring(half-1,half+1);

		return word.substring(half,half+1);
	}
}

```

*   문자열의 길이를 반환해주는 length함수와 원하는 문자를 추출할 수 있는 substring함수를 사용하였다.
*   반환을 위한 String 변수를 따로 선언하지 않고 매개변수를 통해 반환하였다.

## 다른 사람의 풀이 방법

### Best Practice

```java
class Kata {
    public static String getMiddle(String word) {
        int length = word.length();
        return (length % 2 != 0) ?  String.valueOf(word.charAt(length / 2)) : word.substring(length / 2 - 1, length / 2 + 1);
    }
}
```
*   변수를 줄이고, 조건 연산자를 통해 코드가 짧아졌다.
*   나만 그렇게 생각할수 있지만 코드의 줄 수가 적다고 좋아보이지 않았고, 뭔가 가독성이 떨어져보였다.

## 배운 점

*  아무 생각없이 코딩하는것이 아니라 타인이 봤을때도 이해할 수 있도록 하려고 노력하게되는 습관을 들이게 된다.

## 반성할 점

*  아직까지 좋은 코드가 어떤것인지 잘 모르겠다. 이번것만 봐도 단순히 코드가 짧은것이 더 좋은지, 가독성이 좋은것이 나은지 잘 모르겠다.
*  단순히 알고리즘, 문법 등을 공부하는것도 좋지만 어떻게 해야 좋은 코딩을 할 수 있는지도 생각해야겠다.
