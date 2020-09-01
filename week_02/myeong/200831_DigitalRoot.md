# Vowel Count

## 문제 설명

*   수의 자리수를 더하는데 이를 일의자리가 나올때까지 반복한다.

## 나의 풀이 방법

```cpp
int digital_root(int n)
{
  int root_sum=0;
    
  while (true) {
    while (n != 0) {
      root_sum += n % 10;
      n = n / 10;
    }
    if (root_sum >= 10) {
      n = root_sum;
      root_sum = 0;
    }
    else
      break;
  }
  return root_sum;
}
```

*   string 변수를 반환하여 그값을 상황에 따라 변하게 하였다.
*   음수일때가 되지 않을 것이라 예상하고 양수로 변환하여 생각하도록 하였습니다. 

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
int digital_root(int Z) {
    return --Z % 9 + 1;
}
```

*   Best Practice와 Clever가 같다.
*   문제에서 원하는 것을 수식으로 간단하게 풀이하였다.

## 배운 점

*   나는 항상 문제를 풀때는 문제에서 말하는 것을 순서대로한다. best practice나 clever를 보면 자주 수식으로 간단하게
    나타내거나 혹은 헤더를 사용하는데 이를 하면서 헤더와 수식에 대해서 다른 방법도 공부하게 되었다.

## 반성할 점

*   내 풀이보다 더 간결하고 더 아는것이 많지만 우선 나는 문제에서 원하는대로 먼저 풀 수 있도록 하는 것이 중요하다.

## Action Item

*   할 수 있다!