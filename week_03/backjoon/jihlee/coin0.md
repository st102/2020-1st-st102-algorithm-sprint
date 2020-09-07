동전 0
=========

## 문제 설명

주어진 동전들의 종류와 가격을 이용하여 가격에 맞는 가장 적은 수의 동전 개수 세기 

## 나의 풀이 방법

```c++
    for (int i = 0; i < coin_num; i++) {
        if (target_price == 0)
            break;
            
        min_coin_num += target_price / coin_type.back();
        target_price = target_price % coin_type.back();
        coin_type.pop_back();
    }
```
가장 값이 큰 동전을 **그리디**  우선순으로 잡아서 차례로 탐색을 하여 개수를 센다. 


## 다른 사람의 풀이 방법
```c++
   sort(coin.begin(), coin.end(), greater<int>()); 
	for (int i = 0; i < N; i++) {
		while (price >= coin[i]) {
			price -= coin[i];
			num++;
		}
	}
	cout << num;
```
이 풀이 방법은 효율적이지는 않으나 내림차순으로 벡터를 정렬하는 점과 while문을 썼다는 점이 다른 풀이와 달라 적게되었다. 나는 벡터를 끝에서 pop해서 썼는데 인덱스로 접근하는게 더 간략해 보안다. 

참고 사이트: <https://medium.com/hyeon-hwang/11047-%EB%8F%99%EC%A0%840-%EA%B7%B8%EB%A6%AC%EB%94%94-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-33d2f6c7311c>

## 배운점 

-벡터 내림차순으로 정렬할때는 sort함수에 greater<int>()를 간편하게 사용할 수 있다.  

## 반성할 점

-문제를 제대로 제대로 안읽어서 처음에 DP문제인줄 알았다. 시간이 걸리더라도 천천히 읽어야겠다.