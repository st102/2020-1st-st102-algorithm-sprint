# Is a number prime?

## 문제 설명

*  prime number을 찾아라.
*  음수가 주어질수도 있다. n번 또는 n/2 보다 작은 시간이 걸리도록 하여라.

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <cmath>
bool isPrime(int num) {
  
  for (int i = 2; i <= sqrt(num); i++)
    if(num % i == 0)
      return false;
  
  return (num > 1)? true : false;
}
```

*  2부터 num의 제곱까지 for문을 반복하며 i을 증가시켜 num을 i로 나눌때 나머지가 존재하지 않으면 false 리턴하고  
*  만약 for문을 빠져나오면 prime이 아닌거나 1보다 작은수니 그를 판단하여 리턴하였다.

### 테스트 코드
```c++
Describe(is_Prime)
{
    It(test_isPrime_given_number_1)
    {
        Assert::That(isPrime(1), Equals(false));
    }
  
    It(test_isPrime_given_prime_number_and_postive)
    {
        Assert::That(isPrime(197), Equals(true));
        Assert::That(isPrime(7), Equals(true));
    }
  
    It(test_isPrime_given_not_prime_number_and_postive)
    {
        Assert::That(isPrime(4), Equals(false));
        Assert::That(isPrime(121), Equals(false));
    }
  
    It(test_isPrime_given_negative)
    {
        Assert::That(isPrime(-197), Equals(false));
        Assert::That(isPrime(-7), Equals(false));
        Assert::That(isPrime(-4), Equals(false));
        Assert::That(isPrime(-121), Equals(false));
    }
  
};
```

*  크게 양수 음수 1일떄로 나누었고 양수일때는 prime일때랑 아닐때로 나누었다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
bool isPrime(int num) {
  if(num==2 || num ==3 || num ==5) 
   return true;
  
  else if(num <=1 || num % 2 ==0 || num % 3 ==0) 
   return false;
  
  else
  {
    for(int i=5; i<=sqrt(num); i+=6 )
     if( (num % i==0) || (num % (i+2) == 0)) return false;
    
    return true;
  
  }
  
}
```

### Clever

```c++
bool isPrime(int num) {
  if(num==2 || num ==3 || num ==5) 
   return true;
  
  else if(num <=1 || num % 2 ==0 || num % 3 ==0) 
   return false;
  
  else
  {
    for(int i=5; i<=sqrt(num); i+=6 )
     if( (num % i==0) || (num % (i+2) == 0)) return false;
    
    return true;
  
  }
  
}
```

*  2와 3, 5에 대한 경우를 미리 if문을 통해 판단해줌으로서 나머지 수들은 6씩 증가시키는 나랑 같은 for문을 이용해주었다.
*  시간 복잡도는 더 낮을수 있어도 내 코드가 더 보기 깔끔한거 같다.