# HighAndLow

## 문제 설명

*   문자열에서 수에따라 처음에는 대문자 그이후에 소문자를 나타내는 문자열을 만든다.

## 나의 풀이 방법

```cpp
#include <string>
#include <cctype>
using namespace std;
class Accumul
{
public:
    static std::string accum(const std::string &s);
};

std::string Accumul::accum(const std::string &s) {
  std::string restr = "";
  int size = s.size();
  for (int i = 0; i < size; i++) {
    for (int j = 1; j <=i+1; j++) {
      if (j == 1) {
        restr+=toupper(s[i]);
      }
      else
        restr+=tolower(s[i]);
    }
    if(i<size-1)  restr += "-";
  }
  return restr;
}
```

*   구구단을 했던게 생각나서 중첩 for문을 사용하였습니다.
*   cctype헤더를 사용하여 문자열에서 원하는 대로 대문자 소문자가 적절하게 나오게 하였습니다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
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

*   stringstream을 사용하여 입력되도록하였고 for문로 돌리며 string(i,tolower(s[i]))로 소문자의 개수를 맞췄다.

## 배운 점

*   string의 기능중 몰랐던 기능을 알게되었다.

## 반성할 점

*   중첩 for문을 string을 알았다면 보다 간단하게 할 수 있었을 것이다.
## Action Item

*   그래도 아이디어는 괜찮았다!!