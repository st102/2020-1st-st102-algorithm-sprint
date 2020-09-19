# Find next Perfect Square

## 문제 설명

*  주어진 숫자의 제곱근이 정수인지 아닌지 판다하여 정수일경우 다음 정수의 제곱근을 리턴하고 아닐경우 -1을 리턴하라.

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <set>

using namespace std;

class TwoToOne
{
public:
    static string longest(const string &s1, const string &s2);
};

string TwoToOne::longest(const string& s1, const string& s2) {
    set<char> strings;
    string result = "";

    for (auto character : s1)  strings.insert(character);

    for (auto character : s2)  strings.insert(character);

    for (auto character : strings)  result += character;

    return result;
}
```

*  c++ STL 라이브러리를 이용하면 정말 편한거 같다.
*  set는 자동 정렬과 중복을 허용하지 않는다는 속성이 있어 strings라는 set container를 이용하여 중복과 정렬을 해주었고
*  이를 이용하여 string을 만들어 리턴해주었다.

### 테스트 코드
```c++
#include <string>
void testequal(std::string ans, std::string sol) {
    Assert::That(ans, Equals(sol));
}
void dotest(std::string a1, std::string a2, std::string expected)
{
    testequal(TwoToOne::longest(a1, a2), expected);
}
Describe(longest_Tests)
{
    It(test_longest_when_two_string_contain_duplicate_character)
    {
        dotest("aretheyhere", "yestheyarehere", "aehrsty");
        dotest("loopingisfunbutdangerous", "lessdangerousthancoding", "abcdefghilnoprstu");
    }
  
    It(test_longest_when_two_string_not_contain_duplicate_character)
    {
        dotest("arevou", "ysimh", "aehimorsuvy");
    }
};

```

*  중복 단어가 포함되어 있는 경우 아닌 경우로 나누어 테스트 코드를 작성하였습니다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <set>
#include <string>

namespace TwoToOne {

std::string longest(const std::string& s1, const std::string& s2) {
  std::set<char> chars(s1.begin(), s1.end());
  for (char c : s2)
    chars.insert(c);
  return std::string(chars.begin(), chars.end());
}

}
```

### Clever

```c++
#include <set>
#include <string>

namespace TwoToOne {

std::string longest(const std::string& s1, const std::string& s2) {
  std::set<char> chars(s1.begin(), s1.end());
  for (char c : s2)
    chars.insert(c);
  return std::string(chars.begin(), chars.end());
}

}
```

*  c++ STL에는 이렇게 반복자를 이용한 생성자가 존재하고 생성자를 이렇게 이용할수 있는지 첨 알게 되었다.

### Others_1

```c++
#include <set>
#include <string>

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2)
    {
        std::set<char> se;
        se.insert(s1.begin(),s1.end());
        se.insert(s2.begin(),s2.end());
        
        return std::string(se.begin(),se.end());
    }
};
```

*  이게 더 보기 코드가 깔끔하고 보기 좋은거 같다.

### Others_2

```c++
#include <string>
#include <random>
#include <chrono>

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2);
};

std::string TwoToOne::longest(const std::string &s1, const std::string &s2)
{
    std::string s3 = s1 + s2;
    std::string a = "";

    for (auto c : (std::string("abcdefghijklmnopqrstuvwxyz")))
    {
        if (s3.find(c) != std::string::npos)
            a = a + c;
    }
    return a;
}
```

*  string만을 이용해 푼게 신기해서 가져와 봤다.
*  a~z까지 string을 만들어서 for문을 이용해 중복과 정렬을 해결해주었다.

## 아쉬운 점

*  이 문제에서는 아쉬운 점이 아니지만 카카오 2번 문제에서도 STL을 생각해냈으면 더 편하게 풀었을거 같다 ㅠㅠ
