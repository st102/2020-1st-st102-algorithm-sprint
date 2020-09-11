# Find The Parity Outlier

## 문제 설명

*   홀수 혹은 짝수가 한개만 있다. 이를 찾아내라.

## 나의 풀이 방법

```cpp
int FindOutlier(std::vector<int> arr)
{
  std::vector<int>::iterator itor=arr.begin();
  std::vector<int> odd;
  std::vector<int> even;
  for(; itor != arr.end(); itor++) {
    if(*itor % 2 == 0) {
      even.push_back(*itor);
    } else odd.push_back(*itor);
  }
  if(even.size()==1) {
    return even[0];
  }
  else return odd[0];
}

Describe(Test_Cases)
{
    It(Simple_Tests)
    {
        test_for_odd({2, 3, 4}, 3);
        test_for_even({1, 2, 3}, 2);
        test_for_negative_odd({-4, 1, -3, 5, 9}, 4);
        test_for_negative_even({-5, 4, 2, -8, 12}, -5);
        test_for_high_number({123, 456, 789, 155}, 456);
    }
};
```

*   vector arr을 for문으로 첫번째부터 돌리며 짝수 홀수를 나눠 각 vector 변수들에 대입한다.
*   for문이 끝난후 if문으로 1일때를 찾아 return한다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
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

*   for문을 돌리며 ? 연산자로 even일때 odd일때를 나눠 ++을 한다음 return에서 작은 수를 리턴함으로
    원하는 값이 나오도록 하였다.

## 배운 점

*   vector 연산자로 문제를 풀이함으로 vector에 대해 좀더 알게 되었다.

## 반성할 점
*   ?연산자를 쓰면 간단한 문제는 잠 풀이되는 것 같다. 한번 사용하는 습관을 들이는 것도 괜찮을 것 같다.

## Action Item

*   vector 정복 중!!!!