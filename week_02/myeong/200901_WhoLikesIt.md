# Who likes it?

## 문제 설명

*   배열에 들어간 말에 따라 들어갈 텍스트를 반환하도록 한다.

## 나의 풀이 방법

```cpp
using namespace std;

std::string likes(const std::vector<std::string> &names)
{
  string str=" likes this";
  string strs=" like this";
  string restr;
  int others=names.size()-2;
  
  if(names.size()==0) {
    restr="no one"+str;
  }
  else if(names.size()==1) {
    restr=names[0]+str;
  }  
  else if(names.size()==2) {
    restr=names[0]+" and "+names[1]+strs;
  }
  else if(names.size()==3) {
    restr=names[0]+", "+names[1]+" and "+names[2]+strs;
  }
  else if(names.size()>=4) {
    restr=names[0]+", "+names[1]+" and "+to_string(others)+" others"+strs;
  }
    return restr;
}
```

*   if문을 사용하여 각 0,1,2,3일때와 4이상일때를 경우로 나눠 return할 restr에 들어갈 텍스트를 지정하였다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
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

*   Best Practice와 Clever가 같다.
*   switch를 사용하여 경우의 수를 나누었고 4이상일때를 default로 모두다 충족하도록 return하였다.

## 배운 점

*   처음에 case문을 사용하려고 생각했을 때 4이상이라는 생각에 if문을 사용하고자 하였는데 다른 사람의 풀이를 보고
    default가 있었다는 것을 생각하였다.

## 반성할 점

*   case문을 떠올리긴 하였지만 default를 생각 못한게 아쉽다.

## Action Item

*   다른 사람의 풀이가 꼭 답이라는 법은 없다!