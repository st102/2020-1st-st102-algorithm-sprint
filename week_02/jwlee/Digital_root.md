# Disemvowel Trolls

## 문제 설명
i
한 자릿수의 숫자가 나올때까지 각각의 자릿수를 더한다.

## 나의 풀이 방법

```java
public class DRoot {
  public static int digital_root(int n) {


      int sum = 0;

    while (n >= 10) {
       sum += n % 10;
       n /= 10;
    }
      sum += n;

    return sum >= 10 ? digital_root(sum) : sum;

}
  }
```

* 입력이 2자리 수일 때, 자리수를 더하고, 한 자리수가 나올 때까지 반복한다. 

Given n, return the sum of the digits of n. until a single-digit number is produced. using a recursion.


## 다른 사람의 풀이 방법

### Best Practice

```java

public class DRoot {
  public static int digital_root(int n) {
    return n < 10 ? n : digital_root(digital_root (n / 10) + n % 10);
  }
}
```
* 제일 베스트 솔루션인 것 같다. 나도 이생각을 했는데 코드로 옮기지 못했다. 왜 옮기지 못했나 생각해봤는데 인풋  숫자를 꼭 하나 하나씩 분리해서 더해야만 한다는 생각에 사로잡혀서 그런 것 같다. 앞으로는 사고의 유연성을 길러야겠다.

I think this is the best. I thought the same but could not put into words. I tried to figure out why not, I think I was so caught up in a thought I have to split and add one by one. I need to improve the ability to think flexible.


```java
public class DRoot {
  public static int digital_root(int n) {
    return (n != 0 && n%9 == 0) ? 9 : n % 9;
  }
}
```
* 내가 수학 천재가 아닌 이상 이 방법은 떠올리지 못할 것 같으니, 참고하고 넘어간다.


## 배운 점

* 이제 대부분의 문제에서 삼항연산자를 떠올리고 쓸 수 있게 되었다. 베스트처럼 더 간결하게 하려고 노력해봐야겠다. 

* 다른 사람들 코드와 비교해보고 좋은 것은 내 것으로 만들어 다시 써보는 것이 많은 도움이 된다는 것을 알았다.

## 반성할 점

* 처음 코드에서는 while 문에 = 을 붙이지 않아서 stackoverflow 오류가 났었다. 왜 안되냐고 짜증냈는데 침착하게 다시 천천히 돌려보는 연습이 필요할 것 같다. 
