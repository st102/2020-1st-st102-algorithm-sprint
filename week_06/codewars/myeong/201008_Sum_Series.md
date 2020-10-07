#  Sum of the first nth term of Series

## 문제 설명

*   분모가 1부터 3씩 증가하며 분자는 1인 숫자들을 정해진 범위까지의 합을 출력하라. 
    ( 출력을 string이며 소수점을 올림하며 2자리수까지 나타낸다. )

## 나의 풀이 방법
```cpp
#include <string>
#include <math.h>
using namespace std;
std::string seriesSum(int n)
{
  double allsum = 0;
  string restr;
  int remember=0;
  for (int under = 0; under <= n - 1; under++) {
    allsum += 1.00 / (1 + (under * 3));
  }
  allsum=round(allsum*100)/100;
  restr = to_string(allsum);
  for (int index = 0; index <= restr.length(); index++) {
    if (restr[index] == '.')
      remember = index;
  }
  return restr.substr(0,remember+3);
}

Describe(Tests)
{
    It(ExampleTests)
    {
        std::string expected = "0.00";
        std::string actual = seriesSum(0);
        Assert::That("\n" + actual, Equals("\n" + expected));
        
        expected = "1.77";
        actual = seriesSum(9);
        Assert::That("\n" + actual, Equals("\n" + expected));
    }
};
```

*   allsum 변수를 지정한 후에 for문으로 문제에서 원하는 수를 더할 수 있도록 한다. 여기서 1.00으로 소수점이 나올 수 있도록 했습니다
*   이후 round함수를 사용하여 반올림한 값을 to_string으로 변환한뒤 for문을 돌려 .을 찾고 substr로 처음과 .이후 소수점 두자리 
    수까지 나오도록 .을 찾은 index값을 remeber에 넣어 +3을 해줍니다.

## 다른 사람의 풀이 방법

### Best Practice

```cpp
#include <iomanip>

using namespace std;

string seriesSum(int n)
{
    double ret = 0.0;
    double base = 1.0;
    while (n--) {
      ret += 1 / base;
      base += 3;
    }
    stringstream retss;
    retss << setprecision(2) << fixed << ret;
    return retss.str();
}
```

*   while문을 돌려 값을 더한 뒤 stringstream으로 retss을 지정하고 이를 fixed에서 소수점 2자리 수까지로 지정하고 
    문자열로 출력하였다.

### Clever

```cpp
std::string seriesSum(int n)
{
    float sum = 0;
    char str[3];
    for(auto i = 0; i < n; i++) sum += 1./(3*i+1);
    sprintf(str, "%.2f", sum);
    return str;
}
```

*   for문을 돌려 값을 더한뒤 sprintf를 사용하여 합에서 소수점 두자리 수까지 구한 것을 str에 넣어 출력하였다.

## 배운 점

*   setprecision과 %.2f방법들을 구글링을 통해서 알고 있었지만 이를 활용할 수 없었는데 활용하는 방법을 알게되었습니다.

## Action Items

*   코드는 길지만 문제를 푸는걸 포기하지 않는 나를 칭찬해 다음에는 배운거 활용해서 best code를 작성해보자!