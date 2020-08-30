# Get the middle character

## 문제 설명

*  주어진 string의 중앙에 있는 글자를 알아낸다
*  string의 길이가 홀수일경우 1글자를 짝수일 경우 2글자를 반환한다.

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include <iostream>  

using namespace std;

string get_middle(string input){
  return input.length() % 2 == 0 ? input.substr( input.length() / 2 - 1, 2) : input.substr( input.length() / 2, 1);
}
```
*  삼항연산자를 이용하여 주어진 문자열의 길이가 홀수인지 짝수인지 구분하였고,
*  그에 따라 문자열을 return 해주었다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
std::string get_middle(std::string input) 
{
  int i = input.length();

  if ((i % 2) == 0) 
    return input.substr(i/2 - 1, 2);
    
  else
    return input.substr(i/2, 1);
}
```

*  이번 문제를 보니 if문을 사용한 사람들이 많았다..
*  아직도 헥삼항 연산자와 if문을 사용하는 상황에 대하여 헷갈린다.
*  조금더 많은 문제를 풀면 익숙해져야 할거 같다.

### Clever

```c++
std::string get_middle(std::string input) 
{
  return input.substr((input.size()-1)/2,(input.size()+1)%2+1);
}
```

*  나도 처음에 이 생각을 했지만 substr에 넘겨줘야하는 데이터를 통합시킬수 없다고 생각했었다.
*  하지만 이 코드를 보니 내생각이 짧고 빠르게 포기했었던거 같다.

### Others

```c++
std::string get_middle(std::string input) 
{
  return input.substr((input.length()-1) / 2, (input.length())%2 == 0 ? 2 : 1);
}

```

*  개인적으로 생각하는 best pratice이다. 코드도 짧고 내용도 한눈에 들어오는 거 같다.

## 배운 점

*  중앙의 index를 계산할떄 나는 (길이 / 2 - 1) 을 했지만 이러면 안되고  (길이 - 1) / 2 수식을 이용해야 한다!

## 반성할 점

*  빠르게 단정짓는 습관이 있는거 같다. 이를 고쳐야한다!

## Action Item

*  많은 상황을 생각하긴 하지만 각각의 상황들을 곰곰히 생각하지 않고 첨에 맞다고 생각하는 상황으로 많이 생각이 집중되는 거같다.
*  연습할떄는 조금더 곰곰히 생각하자!
