# Vowel Count

## 문제 설명

*  주어진 정수보다 작은 자연수들중 3과 5의 배수들의 합을 구하라
*  만약 주어진 수가 음수일 경우 0을 반환한다.

## 나의 풀이 방법

### 문제 풀이 코드
```c++
int Mutiples(int number) 
{
  int sum = 0;
  
  if (number <= 0) return 0;
  
  for ( int i = 1; i < number; i++){
    if (i % 3 == 0 || i % 5 == 0) sum += i;
  }
  
  return sum;
}

```
*  if문을 통해 3과 5의 배수 여부를 확인을 통해 합을 구하였다.

*  
### 테스트 코드
```c++
Describe(solution_algorithm)
{
    It(test_code_number_is_10)
    {
        Assert::That(solution(10), Equals(23));
    }
    It(test_code_number_is_30)
    {
        Assert::That(solution(30), Equals(195));
    }
    It(test_code_number_is_0)
    {
        Assert::That(solution(0), Equals(0));
    }
    It(test_code_number_is_negative)
    {
        Assert::That(solution(-5), Equals(0));
    }
};
```

*  테스트 코드는 주어진 먼저 주어진 수가 10과 30과 같은 자연수인 경우와 0일 경우 그리고 음수일 경우를 테스트 하였다.

## 다른 사람의 풀이 방법

### Best Practice

```c++
int solution(int number) 
{
  int sum = 0;
  for (int n = 3; n < number; n++) {
    if ((n%3 == 0) || (n%5 == 0))
      sum += n;
  }
  return sum;
}
```

* 많은 사람들이 if문을 통해 비슷하게 문제를 풀이하였다. 
* 하지만 for문의 처음 숫자의 시작이 3부터 시작하는 사소한 차이를 통해 주어진 숫자가 0,1,2인 경우를 제외해줄수 있을 뿐만아니라 for문의 반복 횟수도 줄일수 있었다.
* 이러한 사소한 차이가 큰 결과의 차이를 가져오는것 같다

### Clever

```c++
int solution(int number) 
{
  int d3 = (number-1)/3;
  int d5 = (number-1)/5;
  int d15 = (number-1)/15;
  return (3+d3*3)*d3/2 + (5+d5*5)*d5/2 - (15+d15*15)*d15/2;
}
```

*  알고리즘보다 수학적 계산을 이용하여 문제를 풀이하였다. 
*  이런식으로도 코드를 간결하게 할 수 있었던걸 알 수 있었다.
*  하지만 개인적으로 가독성이 부족한 코드인거 같다.

## 배운 점

*  사소한 조건하나로 많은 결과의 차이를 알수 있었다. 조건 하나하나도 신중히 작성해야할거 같다.
*  무조건 알고리즘을 통해 풀기보다 수학적 아이디어를 통해서도 코드를 간결하게 있을수 있다는 걸 알수 있었다.

## 반성할 점

*  for문을 무조건 0이나 1부터 시작하는 습관이 있었는데 이제는 문제에 따라 유연하게 적는 습관을 가져야 할거 같다.

## Action Item

*  코드를 한번짜고 끝내지 말고 작성하고 한번더 생각하는 습관을 갖자.
