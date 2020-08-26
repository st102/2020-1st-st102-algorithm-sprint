# Even or Odd

## 문제 설명

*   주어진 수가 짝수 인지 홀 수 인지 판단해서 알맞은 string을 리턴한다

## 나의 풀이 방법

```java
public class EvenOrOdd {
    public static String even_or_odd(int number) {
        if (number % 2 == 0) return "Even";
        else return "Odd";
    }
}
```

*   짝수 홀수는 2의 배수냐 아니냐로 나눌 수 있기 때문에 나머지 연산을 통해 구하였다.
*   간단한 if else 의 컨벤션 코드법을 적용했다. 내가 원래 써놓았던 코드보다 깔끔하다.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class EvenOrOdd {
    public static String even_or_odd(int number) {
        return (number%2 == 0) ? "Even" : "Odd";
    }
}
```

*  삼항 연산자를 사용한 코드이다. ' (조건문) : ? 참 : 거짓 ' 문법을 익혀두자. IF문을 라인 수를 줄일 수는 있으나 컴파일 속도가 빨라지는 것은 아니라고 한다.
*  또한 중복해서 처리할 경우 가독성이 떨어질 수 있음을 알아두자

### Clever

*   이번 Clever 풀이는 Best 풀이와 동일했다. 

## 배운 점

*  오늘은 삼항 연산자를 이용해봤다. 이렇게 조금씩이라도 자바 문법을 공부해 가면 분명 도움이 될 것같다.

## 반성할 점

*   문제가 간단해 딱히 없다.

## Action Item

*   일요일 코딩 없는 날에는 그동안 썼던 md파일을 한번 훑어보자
*   다음코드에 삼항연산자를 쓸 일이 있으면 활용해보자
