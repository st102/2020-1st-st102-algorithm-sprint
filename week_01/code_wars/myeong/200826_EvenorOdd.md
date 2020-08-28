# Vowel Count

## 문제 설명

*   짝수 홀수를 판별한다.

## 나의 풀이 방법

```cpp
using namespace std;
std::string even_or_odd(int number) {
  string integer_function;
  if (number < 0) {
    number = -number;
  }

  if (number % 2 == 1) {
    integer_function = "Odd";
  } else if (number % 2 == 0) {
    integer_function = "Even";
  }
  return integer_function;
}
```

*   string 변수를 반환하여 그값을 상황에 따라 변하게 하였다.
*   음수일때가 되지 않을 것이라 예상하고 양수로 변환하여 생각하도록 하였습니다. 

## 다른 사람의 풀이 방법

### Best Practice

```cpp
std::string even_or_odd(int num) 
{
  return (num%2==0)?"Even":"Odd";
}
```

*   조건부 연산자인 ?를 사용하여 아주 간단하게 풀이를 하였다.

###Clever

```cpp
std::string even_or_odd(int number) 
{
  return number&1 ? "Odd" : "Even";
}
```

*   Best Practice와 거의 비슷하게 조건부 연산자인 ?를 사용하여 풀이를 하였다.

## 배운 점

*   두 가지인 경우를 할때는 if문보다는 조건부 연산자가 보다 간결하게 할 수 있다는 것을 알게되었다.

## 반성할 점

*   내 풀이보다 다른사람들의 풀이가 더 간결하다.
*   알면알수록 더 간단하게 만들 수 있다.

## Action Item

*   저런 문제를 보았을때 조건부 연산자로 한줄로 끝낼 수 있도록 열심히 공부해야겠다.