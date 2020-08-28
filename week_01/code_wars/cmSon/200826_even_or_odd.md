# Even or Odd

## 문제 설명

*  주어진 정수가 짝수인지 홀수인지 판단하라

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include <iostream>

using namespace std;

string even_or_odd(int number) {
  string check_number_type;

  (number % 2) == 0 ? (check_number_type = "Even") : (check_number_type = "Odd");
  
  return check_number_type;
}

```
*  주어진 수를 2로 나누어 나머지를 통해 홀수 짝수 여부를 판단하였다. 3항 연산자를 이용하였다.

*  
### 테스트 코드
```c++
Describe(solution_algorithm)
Describe(even_or_odd_method)
{
    It(tests_code_number_is_baisc)
    {
        Assert::That(even_or_odd(2), Equals("Even"));
        Assert::That(even_or_odd(1), Equals("Odd"));
        Assert::That(even_or_odd(0), Equals("Even"));
        Assert::That(even_or_odd(7), Equals("Odd"));
        Assert::That(even_or_odd(-1), Equals("Odd"));
    }
};
```

*  테스트 코드는 기본적인 정수에 대하여 테스하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
std::string even_or_odd(int num) 
{
  return (num%2==0)?"Even":"Odd";
}
```

* 내가 처음에 접근했던 방법이랑 비슷하다.
* 나는 return 을 삼항 연산자 안에다 넣었는데 오류가 발생하였었다.
* 문법에 대해 조금더 공부해야할거 같다.

### Clever

```c++
std::string even_or_odd(int number) 
{
  return number&1 ? "Odd" : "Even";
}
```

*  조건부 연산을 이용한 풀이이다. 
*  조건부 연산을 거의 이용한 적이 없는데 이런식으로도 사용할수 있었다는 점이 놀라웠다.
## 배운 점

*  3항 연산자를 이용한 return식을 작성하는 법에 대해 알게되었다.
*  조건부 연산도 잘 이용하며 유용할거 같다.

## 반성할 점

*  문법에 대해 다 안다고 생각했는데 너무 자만했었던가 갖다.

