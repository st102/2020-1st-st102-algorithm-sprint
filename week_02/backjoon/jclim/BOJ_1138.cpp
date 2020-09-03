#include <iostream>

using namespace std;

int num;
int arr[10];

int main(int argc, char** argv)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> num;

	for (int i = 1; i <= num; i++) {
		int height;
		cin >> height;

		int cnt = 0;

		for (int j = 0; j < num; j++) {
			if (arr[j] == 0 && cnt < height) cnt++;
			else if (arr[j] == 0 && cnt == height) {
				arr[j] = i;
				break;
			}
		}
	}

	for (int i = 0; i < num; i++) cout << arr[i] << " ";
}