# Disemvowel_Trolls

## 문제 설명

*  

## 나의 풀이 방법

```java
public class DRoot {
    public static int digital_root(int n) {
        int output = 0;

        while(true) {
            if (n < 10) {
                output += n;
                break;
            }
            output += n % 10;
            n = n / 10;
        }
        if (output >= 10)
            output = digital_root(output);

        return output;
    }
}
```

*  반복문과 재귀함수를 통해 코딩을 하였다.

## 다른 사람의 풀이 방법

### Best Practice

```java
public class DRoot {
  public static int digital_root(int n) {
    return n < 10 ? n : digital_root(digital_root(n/10)+n%10);
  }
}
```
*   재귀함수를 사용한 코드들 중 가장 간결했다.
*   내 코드에서 반복문이 할 일들을 함수의 인자에서 모두 구현했다는게 신선했다.


## 다른 사람의 풀이 방법

### Best Practice

```java
public class DRoot {
  public static int digital_root(int n) {
    return (1 + (n - 1) % 9);
  }
}
```
*   수학과가 왜 코딩을 잘하는지 알게 해주는 코드였다.
*   이런 생각은 어떻게 했는지 궁금하다.

## 배운 점

*  코딩을 잘하기 위해서는 수학적인 사고가 중요하다고 느꼈다.
*  코딩을 할 때, 알고리즘은 어디든지 구현을 할 수 있어야 한다고 생각했다.(리턴, 함수의 인자 등등)

## 반성할 점

*  스터디를 진행하면서 배운것들을 코딩에 적용하려하지만, 막상 코딩을 하면 작 적용이 안되는것같다.
*  의식을 하면서라도 배운것들을 하나하나 생각하면서 적용하는 코딩을 해야겠다.
