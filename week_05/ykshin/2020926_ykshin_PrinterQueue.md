# {프린터 큐}

## 문제 설명
우선순위가 높은 것을 먼저 출력하는 프린터 큐를 조건에 맞춰 출력할 때 원하는 인쇄물이 몇 번쨰로 출력되는가

## 나의 풀이 방법
1. 각 우선순위 별로 리스트를 만들어서 저장하고, 우선순위 큰 것부터 작은 것 까지 순회한다.
2. 주어진 큐를 인덱스를 증가시키며 순회하고 끝에 다다르면 0으로 돌아간다.
3. 현재의 우선순위에 해당 되는 인쇄물이면 지운다.
4. 우선순위에 해당 하지 않으면 index를 1증가시킨다.
5. 현재 우선순위 리스트가 비워졌으면 우선순위를 감소시킨다.
```kotlin
        while (true) {
              if (nowPrirortyQueue.isEmpty()) {
                  nowPrirority--
                  nowPrirortyQueue = queueList[nowPrirority]
                  continue
              }
              if (isTarget(nowPrirority, nowIndex)) {
                  return count
              }
              if (canPrint(nowPrirortyQueue,nowIndex)){
                  nowPrirortyQueue.remove(mainQueue[nowIndex].first)
                  mainQueue.removeAt(nowIndex)
                  count++
              }else{
                  nowIndex++
              }
              if(nowIndex >= mainQueue.size){
                  nowIndex = 0
              }
          }
  
  

```

## 다른 사람의 풀이 방법
비슷한 방법이지만, 자료구조를 다른 방식으로 이용했다.

## 배운 점
- 관리를 위한 자료구조를 하나 더 두어서 해결하는 법

## 반성할 점
- 시뮬레이션은 조건의 분기를 관리하고 재활용이 생명, 모듈화를 더 잘하자

## Action Item
- 하나의 함수는 하나의 역할만!