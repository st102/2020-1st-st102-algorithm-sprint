# {색종이}

## 문제 설명
도화지위에 색종이를 겹쳐서 놓을 때 색종이가 차지한 부분의 넒이를 출력하는 문제

## 나의 풀이 방법
1x1 크기를 한 픽셀로 생각하고, 색종이는 10x10 사이즈로 정해져있다.
각 픽셀을 boolean으로 표현해 true로 바뀐 부분의 갯수를 카운트해 출력한다. 

```kotlin
    val base = Array(BASE_PAPER_SIZE) { BooleanArray(BASE_PAPER_SIZE) }
        for (colorPaperIndex in 0 until n) {
            stringTokenizer = StringTokenizer(bufferedReader.readLine())
            val x = stringTokenizer.nextToken().toInt()
            val y = stringTokenizer.nextToken().toInt()
            for(xIndex in 0 until COLOR_PAPER_SIZE){
                for(yIndex in 0 until COLOR_PAPER_SIZE){
                    base[xIndex+x][yIndex+y] = true
                }
            }
        }
        println(base.sumBy { line -> line.count { pixel-> pixel } })
```

## 다른 사람의 풀이 방법
다들 동일하게 푼 것 같다.

## 배운 점
- 가끔은 바로 보이는게 최적의 방법

## 반성할 점
- 다 짜고 상수로 바꾸지 말고 문제에서 필요한건 바로바로 상수화 하자

## Action Item
- 상수화 습관들이기