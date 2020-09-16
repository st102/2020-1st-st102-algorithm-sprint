# Tribonacci Sequence

## 문제 설명

*  An = An-3 + An-1 + An-2 인 수열을 구하라.
*  첫 3항과 반환해야하는 수열의 크기 n은 인자로 주어진다.   

## 나의 풀이 방법

### 문제 풀이 코드

```c++
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    std::vector<int> result = signature;

    for (int i = 3; i < n; i++){
      int next_number = result[i - 3] + result[i - 2] + result[i - 1];
      result.push_back(next_number);
    }
    if (n < 3) result.resize(n);
    return result;
}
```

*  for문을 통해 수열을 만들어 주었고, n이 3보다 작은경우 size를 줄여 해당 크기만큼의 수열을 반환해준다.

### 테스트 코드
```c++
Describe(Basic_tests)
{
    It(test_code_when_given_111_and_n_is_10)
    {
        std::vector<int> signature = { 1, 1, 1 };
        std::vector<int> expected = { 1, 1, 1, 3, 5, 9, 17, 31, 57, 105 };
        Assert::That(tribonacci(signature, 10), Equals(expected));
    }
    
    It(test_code_when_given_001_and_n_is_10)
    {
        std::vector<int> signature = { 0, 0, 1 };
        std::vector<int> expected = { 0,0,1,1,2,4,7,13,24,44 };
        Assert::That(tribonacci(signature, 10), Equals(expected));
    }
    
    It(test_code_when_given_011_and_n_is_10)
    {
        std::vector<int> signature = { 0, 1, 1 };
        std::vector<int> expected = { 0,1,1,2,4,7,13,24,44,81 };
        Assert::That(tribonacci(signature, 10), Equals(expected));
    }
    
    It(test_code_when_given_100_and_n_is_10)
    {
        std::vector<int> signature = { 1, 0,  0 };
        std::vector<int> expected = { 1, 0, 0, 1, 1, 2, 4, 7, 13, 24 };
        Assert::That(tribonacci(signature, 10), Equals(expected));
    }
    
    It(test_code_when_given_123_and_n_is_10)
    {
        std::vector<int> signature = { 1,2,3 };
        std::vector<int> expected = { 1,2,3,6,11,20,37,68,125,230 };
        Assert::That(tribonacci(signature, 10), Equals(expected));
    }
    
    It(test_code_when_given_123_and_n_is_2)
    {
        std::vector<int> signature = { 1,2,3 };
        std::vector<int> expected = { 1,2 };
        Assert::That(tribonacci(signature, 2), Equals(expected));
    }
    
    It(test_code_when_given_12x_x_is_lower_than_10_and_n_is_0)
    {
        int third = rand() % 10;
        std::vector<int> signature = { 1,2, third };
        std::vector<int> expected = {};
        Assert::That(tribonacci(signature, 0), Equals(expected));
    }
};
```

*  n = 10일때 첫 3개의 항의 조합을 다양하게 만들었고, n=2,n=0 일때 대해서 테스트 코드를 작성하였습니다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    if(n<3){
       signature.resize(n);
    }
    for(unsigned int i = 3; i<n;i++){
      signature.push_back(signature[i-3]+signature[i-2]+signature[i-1]);
    }
    return signature;
}
```

### Clever

```c++
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    if(n<3){
       signature.resize(n);
    }
    for(unsigned int i = 3; i<n;i++){
      signature.push_back(signature[i-3]+signature[i-2]+signature[i-1]);
    }
    return signature;
}
```

*  나랑 정확히 같은 코드이다.

### Other

```c++
#include <numeric>
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
    while(signature.size() < n)
        signature.push_back(std::accumulate(signature.cend() - 3, signature.cend(), 0, std::plus<int>()));
    while(signature.size() > n)
        signature.pop_back();
    return signature;
}
```
*  resize를 쓰는 대신 while문을 사용하였다. accumulate함수를 사용하였는대 이것도 괜찮은 함수인거 같다.

## 배운 점

*  accumulate함수를 통해 다양한 계산을 쉽게할수 있다는 것을 알게 되었다.

## Action Item

*  이제는 랜덤 경우에 대한 테스트 코드도 작성해보자!