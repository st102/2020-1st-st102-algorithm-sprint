#include <iostream>
#include <string>

using namespace std;

int main() {

	int input;
	int sum=0;
	cin >> input;

	if (input < 0) { cout << 0; }


	for (int i = 1; i < input ;i++) {
		
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
		
	}
	cout << sum;
}

