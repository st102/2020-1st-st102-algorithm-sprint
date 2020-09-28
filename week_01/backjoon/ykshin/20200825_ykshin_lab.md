# {연구소}

## 문제 설명
주어진 지도에서 바이러스가 최소한으로 퍼지게 하는 경우를 찾아 감염이 안된 방의 최대 개수를 구하는 문제

## 나의 풀이 방법
벽을 무조건 3개만 지어야 하기에 만들 수 있는 조합을 3중 for문으로 벽을 놓을 수 있는 모든 경우를 탐색한다.
벽을 짓고, 바이러스를 모두 퍼뜨린 후, 감염이 안된 방의 개수를 구한다.

3중 for문으로 벽을 만들 수 있는 경우의 수를 모두 탐색한다. 하나의 정수로 2차원 인덱스를 표현하기 위해 행(int / 열의 갯수) 열(int % 열의 갯수) 로 표현한다.
벽은 0인 곳 에만 설치할 수 있기 때문에, 다음 작업 전에 이를 먼저 체크하여 실행시간을 감소한다. 모두 설치할 수 있는 케이스를 찾으면 확인한다. 이때 깊은 복사로 배열을 전달하여 다음 함수에서 작업한 내용이 영향을 안주게 한다. 
```kotlin
fun buildWall(n: Int, m: Int, array: Array<Array<Int>>): Int {
    var max = Int.MIN_VALUE
    for (i in 0 until n * m - 2) {
        if (array[i / m][i % m] != 0) continue
        array[i / m][i % m] = 1
        for (j in i until n * m - 1) {
            if (array[j / m][j % m] != 0) continue
            array[j / m][j % m] = 1
            for (k in j until n * m) {
                if (array[k / m][k % m] != 0) continue
                array[k / m][k % m] = 1
                val new = check(deepCopy(array, n, m))
                if (new > max) max = new
                array[k / m][k % m] = 0
            }
            array[j / m][j % m] = 0
        }
        array[i / m][i % m] = 0
    }
    return max
}
```

전달된 2차원 배열을 탐색하며 바이러스가 있는 곳을 찾는다. 만약 바이러스가 있는 방이라면, DFS로 상하좌우를 방문하며 바이러스를 퍼뜨린다.
```kotlin
fun check(array: Array<Array<Int>>): Int {
    for (row in array.indices) {
        for (col in array[row].indices) {
            if (array[row][col] == 2) {
                recursiveSpread(row, col, array)
            }
        }
    }
    return array.sumBy { it.count { it == 0 } }
}

fun recursiveSpread(row: Int, col: Int, array: Array<Array<Int>>) {
    if (col > 0 && array[row][col - 1] == 0) {
        array[row][col - 1] = 2
        recursiveSpread(row, col - 1, array)
    }
    if (col < array[row].size - 1 && array[row][col + 1] == 0) {
        array[row][col + 1] = 2
        recursiveSpread(row, col + 1, array)
    }
    if (row > 0 && array[row - 1][col] == 0) {
        array[row - 1][col] = 2
        recursiveSpread(row - 1, col, array)
    }
    if (row < array.size - 1 && array[row + 1][col] == 0) {
        array[row + 1][col] = 2
        recursiveSpread(row + 1, col, array)
    }
}

fun deepCopy(array: Array<Array<Int>>, n: Int, m: Int): Array<Array<Int>> {
    return Array(n) { i -> Array<Int>(m) { j -> array[i][j] } }
}
```



## 다른 사람의 풀이 방법
queue를 이용하여 BFS로 바이러스를 퍼뜨리는 방법이다. 
완전 탐색이기에 시간복잡도 상에서의 차이는 없을 것 같다.
```cpp
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

## 배운 점

중간에 함수명을 바꾸기 위해서 리포멧을 사용했는데, 단축키가 불편해서 이를 변경했다. 매번 불편하게 사용하던 단축키를 편하게 바꾸니 좋다... ㅎ

## 반성할 점

완전탐색이라하더라도 3중 포문을 사용하는 것은... 좋지 않은 구조인 것 같다. 만약 지도의 크기가 커진다면, 분명 시간 초과가 날 것이다. 단순히 조합으로 모든 경우를 탐색하기 보다, 다른 방법이 있지않을까 고민해봐야할 것 같다.


## Action Item
- 3중 포문 대신 다른 방안을 고안해봐야겠다.