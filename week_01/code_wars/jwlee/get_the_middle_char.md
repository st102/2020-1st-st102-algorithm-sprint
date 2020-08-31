# Get the middle character

## 문제 설명

* 주어진 단어의 가운데 문자 출력


## 나의 풀이 방법

```java

class Kata {
  public static String getMiddle(String word) {

  int length = word.length();
    int half = length / 2;
    boolean Even = length % 2 == 0;


    return Even ? word.substring(half-1,half+1) :
                  word.substring(half,half+1);


  }
}

> 문자열을 받아 홀짝을 판별하고 홀수면 하나, 짝수면 두개를 출력한다. 삼항연산자를 이용했다. 가독성을 위해 Even 이라는 true / false bool 반환 문장을 선언했다. 

decide if the given word is even or odd, return the middle if it's odd, the middle two if it's even. used ? operator.


## 다른 사람의 풀이 방법

대부분이 나와 같은 방법으로 풀었고, 눈에 띄는 것 두개를 가져왔다. 



class Kata {
  public static String getMiddle(String word) {
        int l = word.length();
        return word.substring(l / 2 - (1 - l % 2), l / 2 + 1);
  }
}

홀수 짝수 판별 부분만 다르고 아이디어는 같다. (1 - length % 2).


class Kata {
  public static String getMiddle(String word) {

    if (word.length() > 2)
      return getMiddle(word.substring(1,word.length()-1));

    return word;
  }


재귀를 사용했다. 만약 word 의 길이가 길다면 에러가 날 것 같다. 딱히 재귀를 쓸만한 문제는 아니라서 clever 지만 best 는 아닌 것 같다. 

used recursion. the problem is to get StackOverflowError when word.length() is too big.
IMHO, I don't think a recursion is that necessary with this case. clever, though.


## 배운점

substring 과 charAt 메소드에 대해서 다시한번 공부했다. 이제 진짜 익숙해진 것 같다!

got used to substring and charAt !

## 반성할 점

testcase 가 돌아가지 않으면 코드 전체를 뜯어고치려고 하는 습관이 있는 것 같다. 그전에 오탈자나 메소드를 정확히 썼는지 천천히 확인해야겠다.

## Action Item
아는 메소드가 별로 없어서 쉽게 풀 수 있는 것을 어렵게 푸는 경우가 있는 것 같다. 더 공부하자.
