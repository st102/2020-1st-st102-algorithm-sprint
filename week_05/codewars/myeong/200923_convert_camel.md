#  Convert string to camel case

## 문제 설명

*   -또는 _의 문자가 왔을 때 그 문자를 지우고 그다음 문자를 대문자화한다.

## 나의 풀이 방법
```cpp
#include <string>

using namespace std;

std::string to_camel_case(std::string text) {
  string restr;
  for(int i=0; i<text.length(); i++) {
    if(text[i]=='_' || text[i]=='-') {
      restr+=toupper(text[i+1]);
      i++;
    } else restr+=text[i];
  }
  return restr;
}

Describe(Testing_function_to_camel_case)
{
    It(Basic_tests)
    {
        Assert::That(to_camel_case_zero(""), Equals(""));
        Assert::That(to_camel_case_normal("seong-myeong-geun"), Equals("seongMyeongGeun"));
        Assert::That(to_camel_case_complex("The-Stealth_Warrior"), Equals("TheStealthWarrior"));
        Assert::That(to_camel_case_toupper("A-B-C-D-E-F"), Equals("ABCDEF"));
    }
};
```

*   문자열 크기만큼 for문을 돌리며 restr변수에 -또는 _를 만났을 때 그 다음 문자를 대문자로 변경하여 입력한다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
#include <string>

std::string to_camel_case(std::string text)
{
  for(int i = 0; i < text.size(); ++i)
  {
    if(text[i] == '-' || text[i] == '_')
    {
      text.erase(i,1);
      text[i] = toupper(text[i]);
    }
  }
  return text;
}
```

*   새 문자열을 만들지 않은채 -나 _를 만났을 때 erase를 사용하여 문자열을 지우고 지워진 만큼 위치가 이동하여 i를 바로 사용하였다.

## 배운 점

*   string에서는 erase보다는 새로만드는게 실용적이라고 생각했지만 지우는 방법도 좋은 것 같다.

## Action Items

*   항상 for문이 필요한가를 생각했지만 이번문제는 for문이 필요한 문제였다!