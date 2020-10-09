# 05주차 Number of People in the Bus - python

## 문제 설명
* 버스 승하차 인원의 list가 주어졌을 때 마지막에 남아있는 승객 수 return

## 풀이방법
```python
import unittest


def number(bus_stops):
    return sum((stop[0] - stop[1]) for stop in bus_stops)
        

class TestNumber(unittest.TestCase):
    def test_number(self):
        self.assertEqual(number([[3,0],[9,1],[4,10],[12,2],[6,1],[7,10]]),17)


if __name__ == '__main__':
    unittest.main()
```
* 승차인원-하차인원을 다 더한 값을 return 했다.
* 마땅한 testcode를 작성할 방법을 찾지 못했다.

## 다른사람의 풀이방법

### Best practice
```python
def number(bus_stops):
    return sum([stop[0] - stop[1] for stop in bus_stops])
```
* 내가 best다.

### Clever
```python
def number(stops):
    return sum(i - o for i, o in stops)
```
* list의 원소 개수가 정해져있을 때 반복문에서 i, o처럼 2개씩 접근이 가능하다는 것을 알았다.

## 배운점
* 반복문에서 원소 접근 방법.

## 반성할점
* .

## Action Item
* 효율적인 프로그램 작성.