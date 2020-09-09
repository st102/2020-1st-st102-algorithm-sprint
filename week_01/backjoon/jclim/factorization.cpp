#include <iostream>

using namespace std;

int num;

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;

	int i = 2;

	while (num > 1) {
		while (num % i == 0) {
			cout << i << "\n";
			num /= i;
		}

		i++;
	}
}