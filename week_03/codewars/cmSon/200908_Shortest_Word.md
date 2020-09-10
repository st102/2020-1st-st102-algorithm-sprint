# Highest and lowest

## 문제 설명

*  주어진 문자열에서 제일 길이가 짧은 단어의 길이를 구하라

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include<iostream>
#include<sstream>

using namespace std;

int find_short(string str)
{
  int short_word_length = str.length();
  stringstream ss(str);
  string word;
  
  while(ss >> word)
    short_word_length = (short_word_length < word.length())? short_word_length : word.length();
  
  return short_word_length;
}
```

*  저번에 string을 공백을 기준으로 나눌때 알게된 stream을 이용하여 단어를 분리해주었다.
*  그리고 while문을 통해 모든 단어에 접근하였고 삼항연산자를 통해 길이가 젤작은 단어의 길이를 구하였다.

### 테스트 코드
```c++
Describe(Tests)
{
  It(test_code_given_many_word)
  {
    Assert::That(find_short("bitcoin take over the world maybe who knows perhaps"), Equals(3));
    Assert::That(find_short("turns out random test cases are easier than writing out basic ones"), Equals(3));
    Assert::That(find_short("lets talk about javascript the best language"), Equals(3));
    Assert::That(find_short("i want to travel the world writing code one day"), Equals(1));
    Assert::That(find_short("Lets all go on holiday somewhere very cold"), Equals(2));
  }
  
  It(test_code_given_only_one_word)
  {
    Assert::That(find_short("takes"), Equals(5));
    Assert::That(find_short("apple"), Equals(5));
  }
};
```

*  문제에서 빈 문자열과 단어 이외의 것은 포함되어 있지 않다고 하여 단어가 여러개 나올때와 1개만 나올떄의 경우에 대해 테스트 코드를 작성하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <string>
#include <sstream>

int find_short(const std::string &str)
{
    std::istringstream inp(str);
    std::string s;
    int len = -1;
    while (std::getline(inp, s, ' '))
        if (s.length() < len)
            len = s.length();
    return len;
}
```

### Clever

```c++
#include <string>
#include <sstream>

int find_short(const std::string &str)
{
    std::istringstream inp(str);
    std::string s;
    int len = -1;
    while (std::getline(inp, s, ' '))
        if (s.length() < len)
            len = s.length();
    return len;
}
```

*  getline 함수를 이용하여 공백을 구분하여 주었다. 그외의 것은 삼항 연산자를 if문으로 작성했다는 것 이외에는 내 코드와 같은거 같다.
*  나는 내코드가 더 보기 깔끔하다고 생각된다. 조건이 한개이고 실행하는 문장이 한줄일떄는 굳이 if문보다 삼항연자를 사용하는게 더 낫은거 같다.

## 배운점

*  getline함수는 c언어의 strtok 함수랑 같은 기능을 하는 함수 인거같다.
*  구분자를 사용자가 지정하여 구분자까지 문자열을 잘라주는 함수인거같다.

## Action Item

*  getline을 이용하여도 문자열 문제를 쉽게 풀수 있을거 같다.