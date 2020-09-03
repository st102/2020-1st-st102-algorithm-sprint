# WHo like it?

## 문제 설명

*  1자리가 될때까지 각자리수를 계속 더한다.
*  만약 1번 각자리수를 더했는데 1자리수가 아니면 그 덧셈 결과의 각 자리수를 다시 더하는 과정을 반복한다.

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include <iostream>  
#include <vector>
#include <string>

using namespace std;

string likes(const vector<string>& names)
{
	switch (names.size()) {
	  case 0: return "no one likes this";
	  case 1: return names[0] + " likes this";
	  case 2: return names[0] + " and " + names[1] + " likes this";
	  case 3: return names[0] + ", " + names[1] + " and " + names[2] + " likes this";
	  default: return names[0] + ", " + names[1] + " and " + to_string(names.size() - 2) + " likes this";
	}
}
```
*  names의 인자 개수가 없을때, 1개일떄, 2개일때, 3개일때, 그 이상일때로 나누어 각각의 경우에 맞는 text를 만들어 return하도록 하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
std::string likes(const std::vector<std::string> &names){
  switch(names.size()){
    case 0: return "no one likes this";
    case 1: return names[0] + " likes this";
    case 2: return names[0] + " and " + names[1] + " like this";
    case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    default: return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
  }
}
```

*  
### Clever

```c++
std::string likes(const std::vector<std::string> &names){
  switch(names.size()){
    case 0: return "no one likes this";
    case 1: return names[0] + " likes this";
    case 2: return names[0] + " and " + names[1] + " like this";
    case 3: return names[0] + ", " + names[1] + " and " + names[2] + " like this";
    default: return names[0] + ", " + names[1] + " and " + std::to_string(names.size() - 2) + " others like this";
  }
}
```

*  나랑 정확히 같은 풀이라 많이 당황스러웠다..

### Others

```c++
std::string likes(const std::vector<std::string> &names)
{
  const char *templates[] = {
    "no one likes this",
    "%s likes this",
    "%s and %s like this",
    "%s, %s and %s like this",
    "%s, %s and %d others like this"
  };
  const int index = names.size() > 4 ? 4 : names.size();
  
  char buf[1024];
  switch(index) {
    case 0:
      return templates[0];
    case 1:
      sprintf(buf, templates[1], names[0].c_str());
      break;
    case 2:
      sprintf(buf, templates[2], names[0].c_str(), names[1].c_str());
      break;
    case 3:
      sprintf(buf, templates[3], names[0].c_str(), names[1].c_str(), names[2].c_str());
      break;
    case 4:
      sprintf(buf, templates[4], names[0].c_str(), names[1].c_str(), names.size() - 2);
      break;
    }
  return buf; // Do your magic!
}

```

*  신기해서 가져와본 코드이다. 
*  좋은 코드는 아닌거 같지만 sprintf를 이용하면 문장 포맷을 만들고 거기다 단어를 대입할수 있다는 점을 첨 알게되 가져와봤다.

## Action Item

*  이번 문제는 단순히 생각하는게 최선의 정답이다? 라는 점을 알려주고 싶은거 같다.
*  처음 코드를 작성하고 너무 단순해서 다른방법이 있나 곰곰히 생각하고 작성해봤는데 가독성도 떨어지고 코드도 쓸데없이 복접해졌다.
*  때로는 단순한게 최고인거 같다!
*  또한 개인적인 생각으로 조건이 단순하면 단순할수록 swtich 문이 if문도보다 가독성이 좋은거 같다.