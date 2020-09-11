# Find The Parity Outlier

## 문제 설명

*  

## 나의 풀이 방법

```java
package Cote_Package;

public class FindOutlier {
	static int find(int[] integers) {
	    int oddnum = 0;
	    int odd = 0, even = 0;

	    for (int num: integers) {
	        if (num % 2 == 0)
	            even = num;
	        else {
	            oddnum++;
	            odd = num;
	        }
	    }
	    return oddnum > 1 ? even : odd;
	}
}
```

*	 먼저 짝수일 때와 홀수일 때, 각각 변수에 저장하고, 홀수의 개수를 이용해 코딩을 하였다.
*  처음에는 evennum(짝수의 개수)도 선언해서 사용하였는데, 굳이 사용할 필요가 없어서 빼버렸다.



## 테스트 코드
```java
package Cote_Package;
import static org.junit.Assert.assertEquals;

public class Test_find {
	public void testExample() {
	     int[] exampleTest1 = {2,6,8,-10,3};
	     int[] exampleTest2 = {206847684,1056521,7,17,1901,21104421,7,1,35521,1,7781};
	     int[] exampleTest3 = {Integer.MAX_VALUE, 0, 1};
	     assertEquals(3, FindOutlier.find(exampleTest1));
	     assertEquals(206847684, FindOutlier.find(exampleTest2));
	     assertEquals(0, FindOutlier.find(exampleTest3));
	 }
}
```
*  코드워즈의 테스트코드를 사용했다.


## 다른 사람의 풀이 방법

### Best Practice

```java
import java.util.Arrays;

public class FindOutlier{
  static int find(int[] integers){
    int[] odd = Arrays.stream(integers).filter(n -> n % 2 != 0).toArray();
    int[] even = Arrays.stream(integers).filter(n -> n % 2 == 0).toArray();

    return odd.length == 1 ? odd[0] : even[0];
}
}
```
*  전체적인 흐름은 내 코드와 비슷하지만, 스트림을 사용하면서 변수선언을 줄이고 반복문과 조건문을 생략하면서 코드가 간략해졌다.


## 배운 점

*  스트림의 filter에 대해서 보면서, 스트림의 다양한 기능들(map, sorted 등)에 대해서도 자세히 알게되었다.


## 반성할 점

*  개강을 하면서 오히려 게을러진거같다.
*  스스로 핑계를 대지않고 꾸준히 스터디를 해야겠다고 생각했다.
