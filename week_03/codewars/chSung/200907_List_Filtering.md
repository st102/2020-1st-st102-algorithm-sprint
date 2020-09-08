# List Filtering

## 문제 설명

*  양의 정수와 문자열을 받아 양의정수를 필터링해서 새 리스트를 반환해라

## 나의 풀이 방법

```c#

using System.Collections;
using System.Collections.Generic;
using System.Linq;

public class ListFilterer
{
   public static IEnumerable<int> GetIntegersFromList(List<object> listOfItems)
   {
     return listOfItems.OfType<int>();
   }
}

```

*  이번 문제는 내가 그나마 조금이라도 아는 java, c++ 지원이 안됐다 그래서 저번 학기에 배운 C#으로 해봤다.
*  지정된 형식에 따라 요소를 필터링 해주는 메소드이다.
*  베스트 풀이와 동일하다.


## 다른 사람의 풀이 방법

* ### Others

```java
import java.util.*;
import java.util.stream.Collectors;

public class Kata {
  
  public static List filterList(final List list) {
    return (List)list.stream().filter(e -> ! (e instanceof String)).collect(Collectors.toList());   
  }
}
```

*  문자열을 제외하고 숫자만 필터링하는 방법
*  잘 몰라도 람다식을 계속 보다보니까 읽고 이해할 수는 있게 되었다

## 배운 점

*  람다식 표현 복습

## 반성할 점

*   list에 대한 이해가 부족하다 책과 구글을 보고 공부했다.

## Action Item

*   다음 문제부터는 test case를 다뤄 보겠다.
