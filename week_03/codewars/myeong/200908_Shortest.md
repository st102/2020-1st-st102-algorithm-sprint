# Shortest Word

## 문제 설명

*   문자열에서 공백을 기준으로 제일 작은 단어의 수를 출력한다.

## 나의 풀이 방법

```cpp
#include <sstream>
using namespace std;
int find_short(std::string str)
{
  string shortBuffer;
  stringstream ss(str);
  int reshortest = str.length();
  while (getline(ss, shortBuffer, ' ')) {
    if (reshortest > shortBuffer.length()) {
      reshortest = shortBuffer.length();
    }
  }
  
  return reshortest;
}
Describe(Tests)
{
  It(Test_Shortest_Word)
  {
    Assert::That(find_short("my name is seong myeon geun."), Equals(2));
    Assert::That(find_short_overlapping("abc def ghi jkl mno pqr stu vwx yza"), Equals(3));
  }
};
```

*   전에 풀었던 HighAndLow에서 배웠던 ss를 떠올려 사용하였습니다.
*   reshortes를 몇으로 해야할까를 생각하던중 어떤 숫자가 나오더라도 전체문장의 길이보다는 작겠지
    라는 생각으로 reshortest의 처음 값을 전체문장으로 하였습니다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
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

*   istringstream을 사용하여 공백을 기준으로 나누었으며 -1을 len으로 만들어 가장 작은 단어의 길이를 찾았다.

## 배운 점

*   sstream에 대해 더 잘알게 된 것 같다. 작은 수를 정하는데 넣을 것이 없을 때는 음수를 활용하면 된다.

## Action Item

*   배운걸 떠올렸다. 뿌듯하다!!