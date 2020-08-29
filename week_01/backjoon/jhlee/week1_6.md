# 백준 11653 <소인수 분해>

## 문제 설명
입력된 수를 소인수 분해하라.


## 나의 풀이법
```c++

int n;
cin >> n;
int temp = n;

int i = 2;
while(temp != 1) {
	if (temp % i == 0) {
		temp /= i;
		cout << i << '\n';
		continue;
	}
	i++;
}
-->> 수를 입력 받아 해당 수가 나눠지면 나누고 안나눠지면 그 다음 수로 나누게 반복문 사용  


## 다른 사람 풀이

int n, i, j;
scanf("%d",&n);
for(i=2;i*i<=n;i++)
{
	while(n%i==0)
	{
		n/=i;
		printf("%d\n",i);
	}
}
if(n>1) printf("%d\n",n);
-->> 반복문의 조건 때문에 더 효율적일 것 같다.


## 배운 점
반복문의 조건을 더 효율적으로 할 수 있는 방법에 대해 배웠다.




