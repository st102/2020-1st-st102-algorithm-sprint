#include <iostream>

using namespace std;

int main()
{
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
}