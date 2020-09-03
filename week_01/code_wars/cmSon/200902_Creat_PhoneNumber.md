# Creat Phone Number

## 문제 설명

*  주어진 10자리 숫자를 통해 (...) ... - .... 포맷의 전화번호를 만들어라

## 나의 풀이 방법

### 문제 풀이 코드
```c++
#include <iostream>
#include <string>

using namespace std;

string createPhoneNumber(const int arr [10]){
  char phoneNumber[15];
  char *phoneNumber_format = "(%d%d%d) %d%d%d-%d%d%d%d";
  
  sprintf(phoneNumber,phoneNumber_format, 
          arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);

  return phoneNumber;
}
```
*  저번 문제에서 처음 알게된 sprinf를 이용하여 문제를 풀이하였다. 가독성은 좋지 않은듯하다.
*  sprintf를 이용하여 전화번호 포맷에 각자리에 맞는 숫자를 대입하여 전화번호를 만들었다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
#include <string>

std::string createPhoneNumber(const int arr [10]){
  char buf[15];
  snprintf(buf, sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
  return buf;
}
```

*  나랑 같은 방법 sprintf를 이용하여 풀이하였다.

### Clever

```c++
#include <string>

std::string createPhoneNumber(const int digits[10]) {
  std::string res = "(...) ...-....";
  for (unsigned is = 0, id = 0; is < res.length(); is++)
    if (res[is] == '.')
      res[is] = '0' + digits[id++];
  return res;
}
```

*  개인적으로 이방법이 더 가독성이 좋은거 같다.
*  특히, for문 안의 조건을 (auto is ; res)로 했으면 더 좋을거 같다

## 배운 점 
*  아스키 코드를 이용하여 '0' + 숫자 를 하면 굳이 to_string을 사용하지 않아도 된다는 점을 까먹고 있었다 ㅎ
*  sprintf를 이용하는 방법 말고 clever 코드 처럼 포맷을 이용하는 방법이 있는 걸 알게 되었다. 기회가 된다면 사용하고 싶다.

## Action Item

*  특정 포맷을 이용하는 문제는 sprintf를 이용하면 코드가 되게 간결해진다. 하지만 가독성 측면에서는 잘모르겠다.