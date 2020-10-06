# Tribonacci Sequence

## 문제 설명

*   기존의 피보나치와 비슷한 방식의 배열을 만드는다. 기존과 다른 점은 앞의 세 숫자를 더하는 것이다.

## 나의 풀이 방법

```cpp
std::vector<int> tribonacci(std::vector<int> signature, int n)
{
  std::vector<int> result;
  int temp=0;
  
  switch(n) {
      case 0:  return result;
      case 1:  result.push_back(signature[0]);
               return result;
      case 2:  result.push_back(signature[0]);
               result.push_back(signature[1]);
               return result;
      default:
        for(int i=2; i<n-1; i++) {
        signature.push_back(signature[i]+signature[i-1]+signature[i-2]);
      }
      return signature;
  }
}

Describe(Tests)
  {
      It(Test_normal_one)
      {
          std::vector<int> signature = { 1, 1, 1 };
          std::vector<int> expected = { 1, 1, 1, 3, 5, 9, 17, 31, 57, 105 };
          Assert::That(tribonacci(signature, 10), Equals(expected));
      }
      
      It(Test_normal_zero)
      {
          std::vector<int> signature = { 0, 0, 1 };
          std::vector<int> expected = { 0,0,1,1,2,4,7,13,24,44 };
          Assert::That(tribonacci(signature, 10), Equals(expected));
      }

      It(Test_n_2_lower)
      {
          std::vector<int> signature = { 0, 0, 1 };
          std::vector<int> expected = { 0,0 };
          Assert::That(tribonacci(signature, 2), Equals(expected));
      }
      It(Test_n_2_lower_zero)
      {
          std::vector<int> signature = { 0, 1, 1 };
          std::vector<int> expected = { };
          Assert::That(tribonacci(signature, 0), Equals(expected));
      }
  };

```

*   push_back으로 signature에서 배열을 추가하여 나타낼 수 있도록하여 간단하게 리턴하였으나 2이하의 예외가 있어 
    case로 0,1,2 부분만 예외처리를 해주었다.

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
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

*   push_back으로 배열 뒤에 추가하도록 하였으며 2이하의 예외처리를 resize를 통해 줄였다.

## 배운 점

*   resize를 통해 줄이면 넘어가는 부분이 삭제되는 것을 알게 되었다.

## 반성할 점
*   if문을 많이 사용안하기 위해 case문을 사용하였지만 다른사람의 것을 보고 if로 둘을 하니 더 편해보였다.

## Action Item

*   if, case 어떤 방법을 사용할지는 상황에 따라 다르다!