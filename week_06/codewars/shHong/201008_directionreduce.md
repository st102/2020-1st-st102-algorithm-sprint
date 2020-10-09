# 06주차 direction reduce - python

## 문제 설명
* 방향 최소화

## 풀이방법
```python
import unittest


def dirReduc(arr):
    if arr == []:
        return []
    stack = []
    for i in range(len(arr)):
        if stack == []:
            stack.append(arr[i])
        elif stack[-1] == 'NORTH':
            if arr[i] == 'SOUTH':
                stack.pop()
            else:
                stack.append(arr[i])
        elif stack[-1] == 'SOUTH':
            if arr[i] == 'NORTH':
                stack.pop()
            else:
                stack.append(arr[i])
        elif stack[-1] == 'EAST':
            if arr[i] == 'WEST':
                stack.pop()
            else:
                stack.append(arr[i])
        elif stack[-1] == 'WEST':
            if arr[i] == 'EAST':
                stack.pop()
            else:
                stack.append(arr[i])
    return stack


class TestDirReduce(unittest.TestCase):
    def test_dir_reduce(self):
        self.assertEqual(dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]), ['WEST'])


if __name__ == '__main__':
    unittest.main() 
```
* 반대방향이 stack에 들어갔을 때 pop하여 남은 stack을 반환했다.

## 다른사람의 풀이방법

### Best practice
```python
opposite = {'NORTH': 'SOUTH', 'EAST': 'WEST', 'SOUTH': 'NORTH', 'WEST': 'EAST'}

def dirReduc(plan):
    new_plan = []
    for d in plan:
        if new_plan and new_plan[-1] == opposite[d]:
            new_plan.pop()
        else:
            new_plan.append(d)
    return new_plan
```
* opposite이라는 dictionary를 사용해서 반대방향을 저장했다.
* 같은 방식이라도 훨씬 간결해졌다.

### Clever
```python
def dirReduc(arr):
    dir = " ".join(arr)
    dir2 = dir.replace("NORTH SOUTH",'').replace("SOUTH NORTH",'').replace("EAST WEST",'').replace("WEST EAST",'')
    dir3 = dir2.split()
    return dirReduc(dir3) if len(dir3) < len(arr) else dir3
```
* 재귀함수를 이용하여 문자열 길이가 변하지 않을 때 반환했다.

## 배운점
* 문제해결방법?

## 반성할점
* 자료구조를 잘 활용하면 더 좋은 프로그램을 작성할 수 있다.

## Action Item
* 효율적인 프로그램 작성.