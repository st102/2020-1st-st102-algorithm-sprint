#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[1001];
bool visited[1001];

void dfs(int node)
{
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); i++) {
        if (!visited[graph[node][i]])
            dfs(graph[node][i]);
    }
}

int main()
{
    int vertex = 0, edge = 0, s = 0, e = 0, cnt = 0;
    cin >> vertex >> edge;

    for (int i = 0; i < edge; i++) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }

    memset(visited, false, sizeof(visited));
    for (int i = 1; i <= vertex; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}