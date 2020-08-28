#include <iostream>

#include <vector>

#include <cstring>

#include <queue>

#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visited[1001];
queue<int> q;

void dfs(int node){
    cout<<node<<" ";
    visited[node]=true;
    for(int i=0;i<graph[node].size();i++)
        if(!visited[graph[node][i]]) dfs(graph[node][i]);
    
}

void bfs(int start){
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        if(visited[node]) continue;
        cout<<node<<" ";
        visited[node]=true;
        for(int i=0;i<graph[node].size();i++)
            if(!visited[graph[node][i]]) q.push(graph[node][i]);
    }
}

int main(){
    int vertex=0,edge=0,start=0,s=0,e=0;
    cin>>vertex>>edge>>start;

    for(int i=0;i<edge;i++){
        cin>>s>>e;
        graph[s].push_back(e);
        graph[e].push_back(s);
        sort(graph[s].begin(),graph[s].end());
        sort(graph[e].begin(),graph[e].end());
    }
    memset(visited,false,sizeof(visited));
    dfs(start);
    cout<<endl;

    memset(visited,false,sizeof(visited));
    bfs(start);
    cout<<endl;
}