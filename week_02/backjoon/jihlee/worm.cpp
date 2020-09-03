#include <iostream>
#include <queue>
#include <cstring>

#define MAX_SIZE 51
#define DIRECTION_NUM 4
using namespace std;

int graph[MAX_SIZE][MAX_SIZE], worm_num[MAX_SIZE][MAX_SIZE];
int row = 0, col = 0;
int xpos[] = { -1, 0, 1, 0 }, ypos[] = { 0, -1, 0, 1 };

void dfs(int x, int y, int cnt)
{
    if (x < 0 || y < 0 || x >= row || y >= col)
        return;
    worm_num[x][y] = cnt;

    for (int k = 0; k < DIRECTION_NUM; k++) {
        int nx = x + xpos[k];
        int ny = y + ypos[k];
        if (nx < 0 || ny < 0 || nx >= row || ny >= col)
            continue;
        if (graph[nx][ny] == 1 && worm_num[nx][ny] == 0) {
            dfs(x + xpos[k], y + ypos[k], cnt);
        }
    }
}

int main()
{
    int testcase = 0, cab_location = 0, x = 0, y = 0, cnt = 0;
    cin >> testcase;

    for (int t = 0; t < testcase; t++) {
        cin >> col >> row >> cab_location;
        memset(graph, 0, sizeof(graph));
        memset(worm_num, 0, sizeof(worm_num));

        for (int n = 0; n < cab_location; n++) {
            cin >> y >> x;
            graph[x][y] = 1;
        }
        cnt = 1;
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (graph[i][j] == 1 && worm_num[i][j] == 0) {
                    dfs(i, j, cnt);
                    cnt++;
                }
            }
        }
        cout << cnt - 1 << endl;
    }
}