피보나치수5 
=========

## 문제 설명

숫자 소인수 분해 하여 출력하기 


## 나의 풀이 방법

```c++
    int number = 0, prime = 2;
    cin >> number;
    if (number == 1)
        return 0;

    while (number > prime) {
        if (number % prime == 0) {
            cout << prime << endl;
            number /= prime;
            prime = 2;
        }
        else
            prime++;
    }
    cout << prime << endl;
```
prime 변수를 2에서 부터 주어진 숫자가 나눠질 수 있으면 출력하고 prime 변수를 초기화 시킨다. 하지만 나눠지지 않는 경우 prime변수를 증가 시킨다.


## 다른 사람의 풀이 방법
```c++
    if(N == 1)
    return 0;
    
    for(int i = 2; i <= sqrt(N); i++) 
    {
        if(N % i==0)
        {
            N /= i; 
            cout << i << '\n';
            i--; 
        }
    }
    if(N > 1) cout << N << '\n'; 
```
이 풀이 방법은 나눌 prime 숫자를 루트 N까지만 확인하는데 prime이 나눠 떨어지면 출력하고 감소시키도록한다. 

참고 풀이: <https://m-falcon.tistory.com/132>

## 배운점 

-'에라토스테네스의 Idea'에서 임의의 자연수 N이 제곱근 이하에서 소수로 나누어지면 N은 소수가 아니기 때문에 N의 소수는 루트 N까지만 확인해도 된다는 점을 알게 되었다.

그러면서 O(N)이였던 시간복잡도를 O(루트(N))까지 줄일 수 있게 된다. 하지만 대신 나머지 숫자 1개가 발생할 수 있다.
