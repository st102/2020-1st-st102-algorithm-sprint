연구소
=========

## 문제 설명

상하좌우로 퍼지는 바이러스를 막는 3개의 벽을 세워 최대 안전 구간을 구하는 문제


## 나의 풀이 방법

```c++
void mkWall(int cnt){
    if(cnt==3) {
        spread();
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]!=0) continue;
            graph[i][j]=1;
            mkWall(cnt+1);
            graph[i][j]=0;
        }
    }
}
```
**DFS**를 이용해서 세울 수 있는 모든 구간에 3개의 벽을 세운다. 3개의 벽이 다 세워졌을 때 바이러스를 전파하여 안전한 영역을 구한다. 

```c++
void spread(){
    int cnt=0;
    copy(&graph[0][0],&graph[0][0]+8*8,&tmp[0][0]);
    queue<pair<int,int> > pq;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            if(tmp[i][j]==2) pq.push(make_pair(i,j));
    }
    while(!pq.empty()){
        int x=pq.front().first;
        int y=pq.front().second;
        pq.pop();

        for(int k=0;k<4;k++){
            int nx=x+xpos[k];
            int ny=y+ypos[k];
            if(nx>=0&&ny>=0&&nx<N&&ny<M){
                if(tmp[nx][ny]==0){
                    tmp[nx][ny]=2;
                    pq.push(make_pair(nx,ny));
                }
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++)
            if(tmp[i][j]==0) cnt++;
    }
    sArea.push_back(cnt);
}
```
**BFS**를 사용해서 바이러스를 상하좌우 벽이 없는 구간에 퍼지도록 한다. 그리고 마지막에 남은 안전한 영역을 세서 벡터안에 넣고 벡터를 정렬한다음 가장 큰 값을 출력한다. 

## 다른 사람의 풀이 방법
```c++
int wall(){
    for(int j=0; j<listSize-2; j++){
        for(int t=j+1; t<listSize-1; t++){
            for(int r=t+1; r<listSize; r++){
                graph[list3[j].first][list3[j].second]=1;
                graph[list3[t].first][list3[t].second]=1;
                graph[list3[r].first][list3[r].second]=1;
                list3.clear();
                go();
                count();
                if(maxv < count0){
                    maxv=count0;
                }
                graph[list3[j].first][list3[j].second]=0;
                graph[list3[t].first][list3[t].second]=0;
                graph[list3[r].first][list3[r].second]=0;
            }
        }
    }
    return maxv;
}
```
이 풀이 방법은 벽을 세울 때 3중 for문을 사용해서 벽을 세울 수 있는 모든 가능성을 고려해서 벽을 새우고 안전한 영역을 계산하도록하였다. list3에는 graph에 0인 모든 {x,y}이 담겨져 있다. 

참고 사이트: <https://steemitimages.com/1280x0/https://steemitimages.com/DQmV9zKqXg25D5xjmEHk3t26x9ztFVGBEMxBn9N6Ggm1a7X/image.png>

## 배운점 

-이 문제는 배열의 크기가 최대 8*8로 크기가 작아서 벽을 세울 수 있는 가능성을 다 확인해서 볼 수 있었다. 

-2차원 배열은 1차원 배열과 다르게 copy(&src[0][0],&src[0][0]+N*N,&dst[0][0]);
로 복사해야 한다.

-처음에 DFS의 재귀함수 종료 조건으로 벽의 3개를 다 세우면 spread하고 return을 해줘야하는데 return을 까먹어서 헤맸었다. 