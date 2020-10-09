#  Split Strings

## 문제 설명

*   문자열을 두 문자 단위로 벡터에 저장하여라. 문자열 총 홀수이면 마지막 두 문자에는 뒤에 _를 추가하여라.

## 나의 풀이 방법
```cpp
#include <string>
#include <vector>
using namespace std;
std::vector<std::string> solution(const std::string &s)
{
  vector<string> revec;
  string restr;
  int length=s.length();
  int two_count=1;
  for(int index=0; index<length; index++) {
    restr+=s[index];
    if(two_count==2) {
      revec.push_back(restr);
      two_count=0;
      restr="";
    }
    two_count++;
  }
  if(length%2==1) {
    restr=s[length-1];
    revec.push_back(restr+"_");
  }
    return revec;
}

Describe(sample_test)
{
    It(even_length)
    {
       do_test("abcdef", {"ab", "cd", "ef"});
       do_test("HelloWorld", {"He", "ll", "oW", "or", "ld"});
    }
    It(odd_length)
    {
       do_test("abcde", {"ab", "cd", "e_"});
       do_test("LovePizza", {"Lo", "ve", "Pi", "zz", "a_"});
    }
};
```

*   restr 변수를 지정하여 for문에서 2문자로 넣을 수 있도록 추가한다. 이후 two_count를 사용하여 문자 두개가 들어갔을 때 문자열을 초기화를 해주며 2문자씩 벡터에 저장한다.
*   마지막으로 if문으로 홀수인지를 확인한 후에 마지막 문자열에 _를 추가하면서 revec 벡터를 return 한다.

## 다른 사람의 풀이 방법

### Best Practice

```cpp
std::vector<std::string> solution(const std::string &s) {
    std::vector <std::string> res;
    for (int i = 0; i < s.length(); i += 2) res.push_back(s.substr(i, 2));
    if (s.length() % 2) res[res.size() - 1] += "_";
    return res;
}
```

*   substr을 사용하여 2문자열씩 잘라 push_back으로 저장하고 마지막 문자열에서 홀수일때 _를 추가해 주었다.

### Clever

```cpp
#include <string>
#include <vector>
#include <regex>

std::vector<std::string> solution(const std::string &s)
{
    std::regex r{".."};
    auto str = s + '_';
    return {std::sregex_token_iterator(str.begin(), str.end(), r), {}};
}
```

*   regex헤더를 사용하여 ..에 문자열을 넣으며 이에 문제에서 원하는 값이 나오도록 한다.

## 배운 점

*   regex헤더에 대해 알게 되었다.

## 반성할 점

*   문자열을 자르는 방법을 생각했지만 머리아프다고 생각하여 직접하는 방식을 선택한게 아쉽다.

## Action Items

*   훨씬 짧고 유용한 코드를 짤 수 있었을 텐데 익숙함에 속아 효율성을 잊지 말자!