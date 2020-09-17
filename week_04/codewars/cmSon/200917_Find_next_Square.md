# Find next Perfect Square

## 문제 설명

*  주어진 숫자의 제곱근이 정수인지 아닌지 판다하여 정수일경우 다음 정수의 제곱근을 리턴하고 아닐경우 -1을 리턴하라.

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include<cmath>

long int findNextSquare(long int sq) {
  double root = sqrt(sq);
  
  if(root - (int)root == 0)
    return (root + 1)*(root + 1);
  else
    return -1;
}
```

*  cmath 헤더에 있는 sqrt 함수를 이용하여 제곱근을 구하였고, 이를 정수인지 아닌지 판단하였다.

### 테스트 코드
```c++
Describe(findNextSquareTests)
{
    It(test_code_case_return_plus)
    {
        Assert::That(findNextSquare(121), Equals(144));
        Assert::That(findNextSquare(625), Equals(676));
        Assert::That(findNextSquare(319225), Equals(320356));
        Assert::That(findNextSquare(15241383936), Equals(15241630849));
        
    }
    It(test_code_case_return_minus)
    {
      Assert::That(findNextSquare(155), Equals(-1));
      Assert::That(findNextSquare(165), Equals(-1));
    }
};
```

*  단일 단어일경우 길이가 5이상일꺠 아닐때, 문장일경우 길이가 5이상인 단어가 포함될때 아닐때를 구분하여 테스트 코드를 작성하였습니다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <cmath>    
long int findNextSquare(long int sq) {
  if(sqrt(sq) != (int)sqrt(sq)){return -1;}
  return  pow(sqrt(sq) + 1,2);
}
```

### Clever

```c++
#include <cmath>    
long int findNextSquare(long int sq) {
  if(sqrt(sq) != (int)sqrt(sq)){return -1;}
  return  pow(sqrt(sq) + 1,2);
}
```

*  cmath의 pow함수를 사용해서 간단화 하였다.

## 아쉬운 점

*  굳이 정수인지 판단하기 위해 뺼셈을 하지않았어도 될거 같다.
