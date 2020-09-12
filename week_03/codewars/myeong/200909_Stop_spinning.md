# Shortest Word

## 문제 설명

*   문자열에서 공백을 기준으로 제일 작은 단어의 수를 출력한다.

## 나의 풀이 방법

```cpp
#include <algorithm>
#include <string>
using namespace std;
std::string spinWords(const std::string &str)
{
  string wordBuffer;
  string restr;
  stringstream ss(str);
  int eraser_str=str.length();
  int countstr;
  while (getline(ss, wordBuffer, ' ')) {
    countstr=wordBuffer.length();
    if (countstr>4) {
      reverse(wordBuffer.begin(),wordBuffer.end());
    }
    restr+=wordBuffer+" ";
  }
  restr.erase(eraser_str);
  return restr;
}// spinWords

Describe(Tests)
{
  It(Test_Spinning)
  {
    Assert::That(find_short("my name is seong myeon geun."), Equals(my name is gnoes noeym .nueg));
  }
};
```

*   ss를 사용하여 문자열을 공백을 기준으로 검사하도록 while문을 구성하였다.
*   if문으로 각 wordBuffer에서 길이가 5이상인 것을 찾아 reverse를 하였다.
*   원하는 문자열 형식을 맞추기 위해 " "를 추가해주었으며 마지막에 오류가뜨는걸 확인하고 마지막 공백을 지워줄 수 있도록
    erase를 사용하였다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
#include <string>
#include <algorithm>
#include <sstream>
std::string spinWords(const std::string &str)
{
    std::stringstream ss(str);
    std::string result;
    std::string buff;
    while (ss >> buff) {
        if (buff.size() >= 5) {
            std::reverse(buff.begin(), buff.end());
        }
        result += buff + ' ';
    }
    result.pop_back();
    return result;
}
```

*   나와 while문을 돌리는 방식은 비슷하다. 공백을 넣어주면서 while문을 돌렸으며 마지막에 
    pop_back으로 맨끝을 마감해주었다.

## 배운 점

*   vector에서 pop_back을 사용하는줄 알았는데 여기서도 사용이 가능해서 신기했다.

## 반성할 점
*   buff.size()를보고 내 코드에서도 한번 나오는거라 변수에 저장하지 않았어도 될 것 같았을텐데라는 생각이 들었다.

## Action Item

*   TDD하는 방법에 대해서 익숙하지 않아 좀 더 정보를 본 후에 빠른 시일내에 적용하겠습니다.