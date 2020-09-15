# 04주차 Take ten minute walk - python

## 문제 설명
* 입력받은 list의 길이가 10이면서 제자리로 돌아오는 경우 참, 아닐경우 거짓을 반환한다.

## 풀이방법
```python
import unittest


WALK_TIME = 10
NORTH, SOUTH, WEST, EAST = 'n', 's', 'w', 'e'
def is_valid_walk(walk):
    x, y = 0, 0
    for c in walk:
        if c == NORTH: y += 1
        elif c == SOUTH: y -= 1
        elif c == WEST: x += 1
        elif c == EAST: x -= 1
    return True if x == 0 and y == 0 and len(walk) == WALK_TIME else False


class TestIsValidWalk(unittest.TestCase):
    def test_is_valid_walk_with_10_minutes_walk(self):
        self.assertEqual(is_valid_walk(['n','s','n','s','n','s','n','s','n','s']), True)
    def test_is_valid_walk_with_not_10_minutes_walk(self):
        self.assertEqual(is_valid_walk(['n','s']), False)
    def test_is_valid_walk_with_no_return_to_startpoint(self):
        self.assertEqual(is_valid_walk(['n','n','n','s','n','s','n','s','n','s']), False)


if __name__ == '__main__':
    unittest.main()
```
* 동서방향 이동을 x, 남북방향 이동을 y로 했을 때 0이 될 경우 그리고 길이가 10일 경우 참이다.
* 리스트를 한번만 탐색하므로 O(n)의 시간복잡도를 갖는다.

## 다른사람의 풀이방법

### Best practice
```python
def isValidWalk(walk):
    return len(walk) == 10 and walk.count('n') == walk.count('s') and walk.count('e') == walk.count('w')
```
* 간결해 보이지만 count메서드를 실행시킬 때 마다 모든 원소를 탐색하므로 시간이 더 걸린다.(O(4n))
* 나머지는 clever하지 않아서 정하지 않았다.

## 배운점
* .

## 반성할점
* 문제를 이해하는 데 시간이 더 걸렸다. 영어공부를 더 해야할 것 같다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.