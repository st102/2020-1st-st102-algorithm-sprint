# Find The Parity Outlier

## 문제 설명

*  3개 이상의 숫자로 이루어진 배열이 존재한다. 이 배열은 하나의 숫자 N을 제외하고 전부 홀수 또는 짝수로 이루어져 있다.
*  이때 숫자 N을 찾아라

## 나의 풀이 방법

### 문제 풀이 코드

```c++
#include <vector>

using namespace std;

int FindOutlier(vector<int> arr)
{
    int even_result;
    int odd_result;

    int even_count = 0;
  
    for(auto number: arr){
      if(number % 2 == 0) {
        even_result = number;
        even_count++;
      }else{
        odd_result = number;
      }
    }
  
    return (even_count > 1)? odd_result : even_result;
}
```

*  숫자를 홀수 짝수를 구분하여 값을 홀수는 odd_result, 짝수는 even_result에 저장한다.
*  그리고 짝수가 나오는 횟수를 even_count 변수에 저장한다.
*  만약 even_count가 1보다 크면 이 배열에는 홀수 1개와 그외 짝수로 이루어진 배열이니 odd_result를 return하고 반대의 경우 even_result를 반환한다.

### 테스트 코드
```c++
void test_for(std::vector<int> arr, int result)
{
    std::cout << "Testing for {";
    std::string cone = ", ";
    for (std::vector<int>::const_iterator i = arr.begin(); i != arr.end(); ++i)
    {
      if (*i == arr.rbegin()[0]) cone = "";
      std::cout << *i << cone;
    }
    std::cout << "}" << std::endl;
    Assert::That(FindOutlier(arr), Equals(result));
}

Describe(Test_Cases)
{
    It(test_code_when_only_positive_and_not_overlap)
    {
        test_for({2, 3, 4}, 3);
        test_for({1, 2, 3}, 2);
        test_for({2, 6, 8, 200, 700, 1, 84, 10, 4}, 1);
        test_for({1, 4, 5, 11, 13, 31, 17, 81, 99}, 4);
    }
    
    It(test_code_when_only_positive_and_overlap)
    {
        test_for({2, 3, 2}, 3);
        test_for({5, 6, 5}, 6);
        test_for({1, 1, 1, 1, 1, 44, 7, 7, 7, 7, 7, 7, 7, 7}, 44);
        test_for({22, 22, 51, 80, 22, 22, 80, 24, 90}, 51);
    }
    It(test_code_when_only_negative_and_not_overlap)
    {
        test_for({-1, -3, -4}, -4);
        test_for({-5, -2, -4}, -5);
        test_for({-22, -80, -92, -78, -57, -82, -2, -10, -4}, -57);
        test_for({-1, -19, -78, -55, -13, -5, -103, -41}, -78);
    }
  
    It(test_code_when_only_negative_and_overlap)
    {
        test_for({-1, -4, -1}, -4);
        test_for({-5, -2, -2}, -5);
        test_for({-80, -80, -92, -92, -57, -28, -22, -100, -44}, -57);
        test_for({-1, -91, -78, -55, -55, -55, -103, -41}, -78);
    }
  
    It(test_code_when_mixed_negative_positive_and_not_overlap)
    {
        test_for({-5, 2, -4}, -5);
        test_for({1, 2, -3}, 2);
        test_for({-22, 80, -92, 78, 57, 82, -2, -10, -4}, 57);
        test_for({1, 4, -5, -11, 13, 31, -17, -81, -99}, 4);
    }
  
    It(test_code_when_mixed_negative_positive_and_overlap)
    {
        test_for({-5, 2, 2}, -5);
        test_for({7, -4, 7}, -4);
        test_for({-1, -1, -1, -1, -1, -44, 7, 7, 7, 7, 7, 7, 7, 7}, -44);
        test_for({1, 91, 8, -55, -55, -55, -103, 41}, 8);
    }
};
```

*  매번 codewars에서 제공해주는 testcode와는 비슷하지만 이번에는 log기록이 남는 테스트 코드이다.
*  이런식으로 테스트 코드를 작성해도 보기 편리하겠다는 생각을 받았다.
*  테스트 코드는 음수와 양수의 경우, 숫자의 중복 여부의 경우에 따라 각각의 상황에 복잡할때와 간단할때로 나누어 테스트 코드를 작성하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
int FindOutlier(std::vector<int> arr)
{
    int even;
    int odd;
  
    int evenCount = 0;
    int oddCount = 0;
  
    for (auto a : arr)
        a % 2 == 0 ? (evenCount++, even = a) : (oddCount++, odd = a);
  
    return evenCount < oddCount ? even : odd;
}
```

### Clever

```c++
int FindOutlier(std::vector<int> arr)
{
    int even;
    int odd;
  
    int evenCount = 0;
    int oddCount = 0;
  
    for (auto a : arr)
        a % 2 == 0 ? (evenCount++, even = a) : (oddCount++, odd = a);
  
    return evenCount < oddCount ? even : odd;
}
```

*  나랑 문제 접근 방법은 비슷한거 같다. 
*  다른점은 내가 for문안에서 if문으로 표현한것을 이 풀이에서는 삼항연산자를 이용하여 표현하였다. 이런식으로 쉼표를 사용해서 명령어를 사용할수 있다는 것을 까먹고 있었는데 이번 기회에 다시 기억하게 되었다.
*  또한 count 변수를 2개를 이용하여 풀었다. 하지만 굳이 2개를 사용해야 하나 라는 생각이 들었다.

## 배운 점

*  쉼표를 이용하여 명령어를 연결하여 사용할수 있는걸 까먹고 있었다. 이걸 이용하면 코드가 더욱 깔끔해 질수도 있겠다라는 생각이 들었다.
*  테스트 코드를 작성할때 로그가 남도록 작성하는 것도 나쁘지 않는거 같다.

## Action Item

*  codewars 제공해주는 testcode가 아닌 직접 testcode를 짜보자!