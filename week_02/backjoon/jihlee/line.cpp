#include <iostream>
#include <cstring>

using namespace std;
int line[10], order[10];
int main()
{
    int peopleNum = 0;
    cin >> peopleNum;
    memset(line, -1, sizeof(line));

    for (int i = 0; i < peopleNum; i++)
        cin >> order[i];

    for (int i = 0; i < peopleNum; i++) {
        int mysit = -1;
        for (int j = 0; j < peopleNum; j++) {
            if (line[j] == -1)
                mysit++;
            if (mysit == order[i]) {
                line[j] = i + 1;
                break;
            }
        }
    }
    for (int i = 0; i < peopleNum; i++)
        cout << line[i] << " ";
    cout << endl;
}