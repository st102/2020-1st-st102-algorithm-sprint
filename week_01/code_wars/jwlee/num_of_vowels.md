#include <iostream>
#include <string>

using namespace std;



int main() {

	string inputStr;
	int num_of_vowels = 0;

	cin >> inputStr;


	for (int i = 0; i < inputStr.length(); i++) {
		if (inputStr[i] == 'a' || inputStr[i] == 'e' || inputStr[i] == 'i' || inputStr[i] == 'o' || inputStr[i] == 'u')
		{
			num_of_vowels++;
		}
	}

	cout << num_of_vowels;
	
	return 0;
}

> 내가 실제 작성한 코드를 복붙하고 어떤 식으로 풀었는지 코멘트 한다

string 문자열을 받아서 인덱스를 증가시키면서 모음이 있으면 number of vowels 를 하나씩 증가시키는 방법으로 풀었습니다. 
자바로도 풀고 싶습니다.

## 다른 사람의 풀이 방법

> 다른 사람의 풀이 방법 중 괜찮았던 코드를 복붙하고 어떤 식으로 풀었는지 코멘트 한다

#include <string>

int getCount(const std::string& str)
{
   return std::count_if(str.begin(), str.end(), [](int i){return i == 'a' || i == 'e' || i == 'i' || i == 'o'|| i == 'u';});
}

count_if 를 이용해 뒤의 조건이 참인 원소를 세어서 바로 return 했습니다. 아주 짧고 딱봐도 제 코드보다 훨씬 빠르겠습니다.
부럽습니다.

## 배운 점

처음본건지 까먹은건지는 모르겠지만 count_if 와 count 함수에 대해서 공부해보았습니다. 
함수 형태는 value와 같은 값을 세주는 count( begin , end , value ); 와 p의 조건이 참인 원소를 세주는count_if( begin , end , p ); 입니다. 위의 코드처럼 람다를 이용해서 쓰면 아주 유용하겠습니다.

## Action Item
우선 까먹은 함수나 상식이 너무 많습니다. 보이는 함수는 그때그때 정리해서 외우고 써먹을 수 있게 해야겠습니다.
