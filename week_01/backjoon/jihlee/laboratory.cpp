#include <iostream>

#include <cstring>

#include <queue>

#include <vector>

#include <algorithm>

using namespace std;
int graph[8][8], tmp[8][8], r = 0, c = 0,sArea=0;
int xpos[4] = {-1,0,1,0}, ypos[4] = {0,-1,0,1};

void spread() {
  int cnt = 0;
  copy( & graph[0][0], & graph[0][0] + 8 * 8, & tmp[0][0]);
  queue < pair < int, int > > pq;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      if (tmp[i][j] == 2) pq.push(make_pair(i, j));
  }
  while (!pq.empty()) {
    int x = pq.front().first;
    int y = pq.front().second;
    pq.pop();

    for (int k = 0; k < 4; k++) {
      int nx = x + xpos[k];
      int ny = y + ypos[k];
      if (nx >= 0 && ny >= 0 && nx < r && ny < c) {
        if (tmp[nx][ny] == 0) {
          tmp[nx][ny] = 2;
          pq.push(make_pair(nx, ny));
        }
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
      if (tmp[i][j] == 0) cnt++;
  }
  sArea=max(sArea,cnt);
}

void mkWall(int cnt) {
  if (cnt == 3) {
    spread();
    return;
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (graph[i][j] != 0) continue;
      graph[i][j] = 1;
      mkWall(cnt + 1);
      graph[i][j] = 0;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> r >> c;
  memset(graph, 0, sizeof(graph));
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++)
        cin >> graph[i][j];
  }
  mkWall(0);
  cout << sArea<< endl;
}