# {DFS와 BFS}

## 문제 설명
주어진 노드 리스트를 DFS와 BFS로 순회하며 출력한다.

## 나의 풀이 방법
노드를 arrayList에 미리 선언하여 담고 연결된 노드를 추가하여 관리한다.
dfs는 visited 변수를 통해 탐색했는지 안했는지를 판별하며, 재귀로 탐색한다.
bfs는 visited 변수를 통해 탐색했는지 안했는지를 판별하며, queue를 이용해 탐색한다.
```kotlin
fun dfs(now: Int) {
    print("$now ")
    dfsNodeList[now].visited = true
    for (next in dfsNodeList[now].link) {
        if (!dfsNodeList[next].visited) {
            dfs(next)
        }
    }
}

fun bfs(first: Int) {
    val queue = ArrayList<Int>()
    queue.add(first)
    bfsNodeList[first].visited = true
    while (queue.isNotEmpty()) {
        val now = queue.first()
        print("$now ")
        queue.removeAt(0)
        for (next in bfsNodeList[now].link) {
            if (!bfsNodeList[next].visited) {
                queue.add(next)
                bfsNodeList[next].visited = true
            }
        }
    }
}
```



## 다른 사람의 풀이 방법
다들 동일한 방벙으로 해결 한 것 같다.

## 배운 점
dfs와 bfs는 기본적인 틀을 다시 상기했다.

## 반성할 점
트리구조로 안만들고 배열의 인덱스로 접근한 방식이라 야매같은 느낌이든다..ㅎ

## Action Item
- 꾸준히 계속 풀자!