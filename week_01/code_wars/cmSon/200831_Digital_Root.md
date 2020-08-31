# Digital Root

## 문제 설명

*  1자리가 될때까지 각자리수를 계속 더한다.
*  만약 1번 각자리수를 더했는데 1자리수가 아니면 그 덧셈 결과의 각 자리수를 다시 더하는 과정을 반복한다.

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include <iostream>  

using namespace std;

int digital_root(int n)
{
    int check_digit = n  / 10;
  
    if( check_digit == 0){
      return n;
    }else{
      int sum = 0;
      
      while (n != 0){
        sum += n % 10;
        n /= 10;
      }
           
      return digital_root(sum);
    }
  
}
```
*  재귀함수를 이용하여 풀이하였다. 주어진 숫자의 자리 수가 1자리면 그 값을 리턴하였고 아닌 경우 각자리 수의 합을 구한후 재귀호출을 하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
int digital_root(int Z) {
    return --Z % 9 + 1;
}
```

*  
### Clever

```c++
int digital_root(int Z) {
    return --Z % 9 + 1;
}
```

*  이번 문제도 best partice 랑 clever이 같았다.
*  수학적 방법을 이용해 풀었는데, 코드를 보고 난 후에 이해는 되지만 문제를 접했을때 떠오르는 풀이는 아니다.

### Others

```c++
int digital_root(int n)
{
  int digitRoot = 0;
  while(n)
  {
    digitRoot += n%10;
    n = n/10;
  }
  
  return (digitRoot > 9) ? digital_root(digitRoot) : digitRoot;
}

```

*  내가 문제를 보고 최대한 잘 풀었을때 나올수 있는 코드인거 같다.
*  나는 주어진 숫자의 자리수를 보고 판단후 각 자리수 덧셈을 했는데 여기서는 각 자리수 덧셈후 뎃셈 결과의 자리수를 보고 재귀를 할것인지 아닌지 결정하였다.

## 반성할 점

*  숫자 0은 조건문에서 false 값을 사용할수 있다! 기본적인건데 까먹고 있었다.

## Action Item

*  문제를 많이 풀면 풀수록 숫자 관련 문제는 알고리즘보다 수학적 문제 같다.. 수학 공부를 더해야하나..ㅠㅠ