# Vowel Count

## 문제 설명

*   입력받은 자연수보다 적은 수들 중에서 3배수 5배수를 더한값을 출력한다. 

## 나의 풀이 방법

```cpp
int solution(int number) 
{
  int multiple_sum=0;
  
  for(int i=1; i<number; i++)
  {
    if( i%3==0 || i%5==0) 
    {
      multiple_sum += i;
    }
  }
  
  return multiple_sum;
}
```

*   multilple_sum이라는 변수를 지정하여 for문을 돌면서 if문의 조건에 맞을때 그 값을 더하도록 하였다.

## 다른 사람의 풀이 방법

### Best Practice

```cpp
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

*   내가 푼 답과 비슷하지만 이분은 시작 변수의 값을 3으로 1,2를 제외하고 지정하였다.

###Clever

```cpp
int solution(int number) 
{
  int d3 = (number-1)/3;
  int d5 = (number-1)/5;
  int d15 = (number-1)/15;
  return (3+d3*3)*d3/2 + (5+d5*5)*d5/2 - (15+d15*15)*d15/2;
}
```

*   자연수 밑의 수 중에서 3의배수와 5의배수, 15의배수를 찾아 이 합을 return에서 바로하였다.

## 배운 점

*   Clever 풀이하는 방법이 있다는 것도 알게되었다.

## 반성할 점

*   Clever의 풀이를 바로 봤을 때 return을 부분에서 이해하는 것이 살짝 어려웠다. 수학적으로 사고하는 것도 증진하면 좋을 것 같다는 생각이 들었다.

## Action Item

*   쉬운 문제라도 푸는 방법은 다양하다.