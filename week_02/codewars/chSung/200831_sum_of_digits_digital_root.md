# Sum Of Digits / Digital Root

## 문제 설명

*  주어진 n에 대해  Digital Root 값을 구하라.
   (Digital root는 어떤 숫자의 각 digit를 재귀적으로 합한 것을 말한다.)

## 나의 풀이 방법

```java
public class DRoot {
    public static int digital_root(int num) {
        int sum = 0;
        while (num != 0) {
            sum += num % 10;
            num /= 10;
        }
        if (sum < 10) {
            return sum;
        } else {
            return digital_root(sum);
        }
    }
}
```

*   크게 두 가지 풀이가 생각났다. 1번은 162  = 100*1 + 10*6 + 1*2 이런식으로 자릿수 각각 나눠 통째로 구하는 것이고 2번은 스트링식으로 한 자리씩 저장해서 인덱스로 구하는 방법이였다.
*   나머지연산을 쓰면 편할것 같아 1번의 방식으로 결정했다.
*  바로 답이 저장되도록 sum을 만들고 나머지를 이용해 각 자리수 숫자를 빼내어준다(스트링방식으로 치면 각 인덱스에 넣어주는 느낌)
   다음 자리수를 구하기 위해서 10으로 나눈 값을 num에 저장해준다 (반복)
*  마지막 리턴 과정에서 두자리 수 이상일 경우 재귀함수로 불러준다. 



## 다른 사람의 풀이 방법

* ### Best Practice / Clever

```java
 public class DRoot {
   public static int digital_root(int n) {
     return (n != 0 && n%9 == 0) ? 9 : n % 9;
   }
 }
```
  

*  수학적으로 멋있는 풀이다. 자릿수근의 관한 개념이 있거나 10진수와 mod 9의 관계를 잘 이해했다면 이렇게 풀 수도있겠다.
*  https://mathworld.wolfram.com/DigitalRoot.html   // Digital Root 정의 및 수학적 표현
* ' 자릿수근은 9로 나눈 나머지 값이다' 를 이해하면 된다. 물론 10진수 범위 안에서만 이다. (Ex. 10과 1의 mod 9  값이 같음)
*  협업 및 가독성 측면에서는 모르겠다 훌륭한 발상임에는 틀림없다

* ### Others

```java
 public class DRoot {
    public static int digital_root(int n) {
    
      if (String.valueOf(n).length() > 1) {
        int digitSum = 0;
        String numAsString = String.valueOf(n);
        
        for (int i = 0; i < numAsString.length(); i++) {
          int digit = Character.getNumericValue(numAsString.charAt(i));
          digitSum += digit;
        }
        return digital_root(digitSum);
      }
      
      else  {
        return n;
      }  
    }
  } 
```

*   처음에 생각한 string을 이용한 풀이이다. 
*   스트링 이용보다는 숫자를 직접 이용하는 것이 좀 더 논리적이고 수학적인 풀이 같다.

## 배운 점

*   코딩상으로는 두줄이지만 자릿수와 나머지 연산을 활용하는 발상은 좀 오래걸렸다. 퍼즐 푸는 기분이다ㅎㅎ
*   재밌는 수학 규칙을 배웠다.

## 반성할 점

*   재귀함수 쓰는법을 까먹어서 구글링했다;;  얼른 기초를 공부하자

## Action Item

*   문제에서 재귀의 느낌이 나면, 재귀로 꼭 풀어보고, 반복문을 사용해서도 꼭 풀어보도록 하자.

