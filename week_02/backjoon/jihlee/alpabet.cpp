#include <iostream>

#include <cstring>

using namespace std;

int main()
{
    string word;
    cin >> word;

    for (int i = 97; i <= 122; i++) {
        if (word.find((char)i) > word.length())
            cout << -1 << " ";
        else
            cout << word.find((char)i) << " ";
    }
}