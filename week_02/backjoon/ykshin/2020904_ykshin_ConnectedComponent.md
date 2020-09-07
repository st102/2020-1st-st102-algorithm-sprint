# {연결요소의 개수}

## 문제 설명
무방향 그래프에서 간선의 리스트가 주어질 때, 몇개의 그래프로 이루어져있는지 구하는 문제

## 나의 풀이 방법
노드전체를 foreach를 돌리고, 이미 방문한 노드라면 리턴한다. 방문하지 않은 노드라면, 해당 노드를 기준으로 갈 수 있는 모든 정점을 dfs로 방문한다.

```kotlin
   var count = 0
       nodeList.forEach { node ->
           if (node.visited) return@forEach
           count++
           dfs(node)
       }
       println(count)
```
```kotlin
   fun dfs(node: Node) {
       if (node.visited) return
       node.visited = true
       node.linkedList.forEach {
           dfs(nodeList[it])
       }
   }
```

## 다른 사람의 풀이 방법
나와 접근한 방식은 똑같고, 방문하지 않은 노드를 발견했을때 큐를 이용해 정점을 방문한다. dfs,bfs 해당 경우에는 완전탐색을 해야하므로 시간복잡도 상으로는 같을 것 같다.
```cpp
void bfs(int x) {
    if (visited[x] == false) {
        q.push(x);
        visited[x] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i = 0; i<v[x].size(); i++) {
                if (visited[v[x][i].first] == false) {
                    visited[v[x][i].first] = true;
                    q.push(v[x][i].first);
                }
            }
        }
        cnt++;
    }
}
```

## 배운 점
- 이제 간단한 dfs는 10분컷이 가능하다

## 반성할 점
-

## Action Item
- 꾸준히 풀자!