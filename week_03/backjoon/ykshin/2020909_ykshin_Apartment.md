# {단지번호붙이기}

## 문제 설명
주어진 2차원 배열에서 아파트는 1 빈곳은 0. 상하좌우로 연결된 아파트들을 아파트 단지라하면, 아파트 단지가 몇 개 형성되는지 구하는 문제

## 나의 풀이 방법
2차원 배열 전체를 순회하면서, 1이 발견되면 dfs로 연결된 곳을 방문하고 방문한 곳은 0으로 변경한다.그리고 방문할 때마다 +1 된 값을 리턴한다.

```kotlin
val countList = mutableListOf<Int>()
apartmentLists.forEachIndexed { row, apartmentList ->
    apartmentList.forEachIndexed { col, apartment ->
        if (apartment == 1) {
            countList.add(dfs(apartmentLists, row, col))
        }
    }
}

fun dfs(apartmentLists: Array<IntArray>, row: Int, col: Int): Int {
    if (!check(row, col)) return 0
    if (apartmentLists[row][col] == 0) return 0
    apartmentLists[row][col] = 0
    return dfs(apartmentLists, row + 1, col) +
            dfs(apartmentLists, row - 1, col) +
            dfs(apartmentLists, row, col + 1) +
            dfs(apartmentLists, row, col - 1) + 1
}
```

## 다른 사람의 풀이 방법
대부분 비슷하지만 상하좌우를 움직일때 배열에 움직일 좌표를 담아서 하는 방식이 종종 보인다. 해당 방법이 코드의 중복을 줄여주는 것 같다. 
```cpp
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
for(int k=0;k<4;k++) {
   if(now.first + dy[k] < 0 || now.first + dy[k] >= n || now.second + dx[k] < 0 || now.second + dx[k] >= n)continue;
   if(map[now.first + dy[k]][now.second + dx[k]] == 1){
      map[now.first + dy[k]][now.second + dx[k]] = 0;
      q.push(make_pair(now.first + dy[k], now.second + dx[k]));
      }
   }
}
```

## 배운 점
- 배열에 움직일 좌표를 담아서 방문하는 방법! 

## 반성할 점
- 재귀로 1씩 증가하면서 리턴하는 방식이 아직 헷갈린다. 

## Action Item
- 배열에 움직일 좌표를 넣어서 방문하는 거 연습