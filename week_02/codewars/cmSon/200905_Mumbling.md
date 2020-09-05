# Mumbling

## 문제 설명

*  알파벳의 조합으로 이루어진 문자열을 통해 주어진 규칙의 문자열을 만들어라
*  Example
*  accum("abcd") -> "A-Bb-Ccc-Dddd"
*  accum("RqaEzty") -> "R-Qq-Aaa-Eeee-Zzzzz-Tttttt-Yyyyyyy"
*  accum("cwAt") -> "C-Ww-Aaa-Tttt"

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <string>

using namespace std;

class Accumul
{
public:
    static string accum(const string &s);
};

string Accumul::accum(const string &s){
  string return_text="";
  
  for(int i = 0; i < s.length(); i++){
    return_text += (s[i] > 'Z') ? toupper(s[i]) : s[i];
    char lower = (s[i] > 'Z') ? s[i] : tolower(s[i]);
    
    for(int j = 0; j < i; j++){
      return_text += lower;
    }
    
    return_text += '-';
  }
  return_text.pop_back();
  
  return return_text;
}

```
*  for문을 통해 주어진 문자열의 모든 문자에 접근하여 string 헤더 안에 있는 toupper, tolower함수를 이용하여 사용할 대문자와, 소문자를 만들었다. 
*  그리고 중첩 for문을 이용하여 첫대문자 이후 1개씩 증가하는 소문자를 결과 문자열에 이어주었다.

### 테스트 코드

```c++
void testequal(std::string ans, std::string sol) {
    Assert::That(ans, Equals(sol));
}
static void dotest(std::string s, std::string expected)
{
    testequal(Accumul::accum(s), expected);
}
Describe(accum_Tests)
{
    It(test_code_only_upper_sentence)
    {
      dotest("ZALGOUQZ", "Z-Aa-Lll-Gggg-Ooooo-Uuuuuu-Qqqqqqq-Zzzzzzzz");
    }
    It(test_code_only_lower_sentence)
    {
      dotest("hjasdkl","H-Jj-Aaa-Ssss-Ddddd-Kkkkkk-Lllllll");
    }
    It(test_code_basic_sentence)
    {
        dotest("ZpglnRxqenU", "Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu");
        dotest("nyffsGeyylB", "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb");
    }
};
```

* 대문자로만 이루어진 문자열, 소문자로만 이루어진 문자열 그리고 대문자로 시작하는 문자열, 소문자로 시작하는 문자열로 나누어 테스트 코드를 작성하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
using namespace std;

class Accumul
{
public:
    static std::string accum(const std::string &s) {
      stringstream result;
      for (int i = 0; i < s.length(); i++) 
        result << "-" << string(1, toupper(s[i])) << string(i, tolower(s[i])); 
      return result.str().substr(1);
    }
};
```

### Clever

```c++
using namespace std;

class Accumul
{
public:
    static std::string accum(const std::string &s) {
      stringstream result;
      for (int i = 0; i < s.length(); i++) 
        result << "-" << string(1, toupper(s[i])) << string(i, tolower(s[i])); 
      return result.str().substr(1);
    }
};
```

*  c++ 스타일은 stream을 많이 이용하는거 같다.
*  또한 문자열을 이어줄때 stream과 << operator을 이용하였다.
*  그리고 string 객체 생성자를 이용하여 문자열을 만들어주었다. 이를 통해 내가 사용한 중첩 for문이 간단하게 함수로 구현된걸 확인할수있다.
*  마지막으로 만들어진 문자열에서 불필요한 맨처음 '-'을 substr(1)을 통해 제외해주었다.

## 배운 점 

*  stream을 이용하여 문자열을 이어주고 string을 생성할수 있다는 점을 알게되었다.

## Action Item

*  stream을 이용하는 법도 공부하고 연구해야한다!