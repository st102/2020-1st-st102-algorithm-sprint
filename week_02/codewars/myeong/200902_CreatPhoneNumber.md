# Create Phone Number

## 문제 설명

*   배열에 들어간 값들은 각각 핸드폰 번호를 의미하며 이를 합쳐 출력한다.

## 나의 풀이 방법

```cpp
#include <string>
using namespace std;
std::string createPhoneNumber(const int arr [10]){
  string fstr;
  string mstr;
  string lstr;
  string restr;
  for(int i=0; i<3; i++) {
    fstr+=to_string(arr[i]);
  }
  for(int i=3; i<6; i++) {
    mstr+=to_string(arr[i]);
  }
  for(int i=6; i<10; i++) {
    lstr+=to_string(arr[i]);
  }
  
  restr="("+fstr+") "+mstr+"-"+lstr;
  return restr;
}
```

*   334로 핸드폰 번호가 합쳐지므로 to_string으로 int를 string으로 변환시켜 합친다.
*   합친 것들로 문제에서 원하는 출력이 나오도록 한다.

## 다른 사람의 풀이 방법

### Best Practice

```cpp
#include <string>

std::string createPhoneNumber(const int arr [10]){
  char buf[15];
  snprintf(buf, sizeof(buf), "(%d%d%d) %d%d%d-%d%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4], arr[5], arr[6], arr[7], arr[8], arr[9]);
  return buf;
}
```

*   나는 인덱스를 모두 나타내어 return에 넣고자하였는데 불편할까봐 포기했었다. 하지만 이분의 코드에서는 %d로 입력될 
    인덱스들을 따로하여 분류되어 가독성이 높아보인다.

### Clever

```cpp
#include <string>

std::string createPhoneNumber(const int digits[10]) {
  std::string res = "(...) ...-....";
  for (unsigned is = 0, id = 0; is < res.length(); is++)
    if (res[is] == '.')
      res[is] = '0' + digits[id++];
  return res;
}
```

*   res에 출력을 원하는 형태로 만들어놓고 핸드폰 번호가 들어갈 부분에 .을 나타내었으며 for문을 돌면서 .을 만나는 
    부분에 입력하였다.

## 배운 점

*   텍스틑를 붙이는 것만 생각하였는데 해당 인덱스에 교환하는 것도 있다는 아이디어를 알게되었다.

## 반성할 점

*   코드에서 막 가독성이 좋아보이지 않는다.

## Action Item

*   이어붙이는 것 말고도 교환도 있다!