#  Is a number prime?

## 문제 설명

*   숫자가 들어왔을때 이 숫자가 소수면 true를 반환하고 나머지는 false를 반환하라.

## 나의 풀이 방법
```cpp
bool isPrime(int num) {
  
  if(num<=0 || num == 1){
    return false;
  }
  for(int i = 2; i<=sqrt(num) ; i++){
    if(num % i == 0)
      return false;
    
  }
  return true;
}

Describe(is_Prime)
{
    It(Sample_Test)
    {
        Assert::That_zero(isPrime(0), Equals(false));
        Assert::That_one(isPrime(1), Equals(false));
        Assert::That_normal_prime(isPrime(5), Equals(true));
        Assert::That_negative_prime(isPrime(-5), Equals(false));
        Assert::That_high_prime(isPrime(997), Equals(true));
        Assert::That_high_not_prime(isPrime(996), Equals(false));
    }

};
```

*   제곱근의 수까지 for문을 돌리며 num%i를 했을 때 0이 되는지를 확인한다. 다돌고 나왔을 때 소수이므로 true를 반환한다.
*   이외의 숫자들은 모두 if문으로 num<=0;과 num==1로 false 반환한다. 

## 다른 사람의 풀이 방법

### Best Practice & Clever

```cpp
bool isPrime(int num) {
  // your code here..
   
  if(num==2 || num ==3 || num ==5) 
   return true;
  
  else if(num <=1 || num % 2 ==0 || num % 3 ==0) 
   return false;
  
  else
  {
    for(int i=5; i<=sqrt(num); i+=6 )
     if( (num % i==0) || (num % (i+2) == 0)) return false;
    
    return true;
  
  }
  
}
```

*   대표의 소수인 2,3,5를 미리 거르고 i+=6을 통하여 불필요한 버퍼링을 하지 않도록하여 최적의 시간으로 소수를 거를 수 있도록하였다.

## 배운 점

*   소수를 구할때 sqrt 즉 제곱근을 범위로 하면 좋다는 것을 알게 되었다.

## 반성할 점

*   버퍼링을 최대한 줄였다고 생각했지만 더 줄일 수 있는 방법이 있어 놀랍다.

## Action Items

*   이번 문제는 잘 풀었다고 생각했는데 역시 세상은 넓다!