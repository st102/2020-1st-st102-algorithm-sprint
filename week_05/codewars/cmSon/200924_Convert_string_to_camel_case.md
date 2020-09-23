# Convert string to camel case

## 문제 설명

*  "_" 와 "-" 이 포함된 문자열읋 받아서 "-" 과 "_"을 제거하고 그다음 문자는 대문자로 변경하여라

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <string>

using namespace std;

string to_camel_case(string text) {
  
  string result = "";
  
  for(int i = 0; i < text.length(); i++){
    if(text[i] == '-' || text[i] == '_'){
      result += toupper(text[++i]);
    }else{
      result += text[i];
    }        
  }  
  
  return result;
}
```

*  for문을 통해 text 문자열을 검색하고 "-"와 "_"을 만날 경우 i값을 1증가 시켜 대문자로 변경해서 result에 붙어주었다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
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
### Clever

```c++
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

*  새로운 string 변수를 만들지 않고 매개변수 text를 조작하였다. "-" 와 "_"을 만날을때 이를 erase 함수를 통해 제거하고 toupper을 통해 대문자로 변경하였다.

## 배운 점

*  earse함수가 string 내부 함수에도 존재한다는걸 처음 알게 되었다.