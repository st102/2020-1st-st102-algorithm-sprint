# 06주차 Ticket clerk - python

## 문제 설명
* 잔돈반환하기.

## 풀이방법
```python
import unittest


YES = "YES"
NO = "NO"
TICKET_PAY = 25

def tickets(people):
    change = {25:0, 50:0, 100:0}
    for n in people:
        if n != TICKET_PAY:
            returnchange = n - TICKET_PAY
            if returnchange == 25:
                if change[25] < 1:
                    return NO
                else:
                    change[25] -= 1
            elif returnchange == 50:
                if change[50] < 1:
                    if change[25] < 2:
                        return NO
                    else:
                        change[25] -= 2
                else:
                    change[50] -= 1
            elif returnchange == 75:
                if change[50] >= 1 and change[25] >= 1:
                    change[50] -= 1
                    change[25] -= 1
                elif change[25] >= 3:
                    change[25] -= 3
                else:
                    return NO
        change[n] += 1
    return YES
                     

class TestTickets(unittest.TestCase):
    def test_tickets_should_return_YES(self):
        self.assertEqual(tickets([25,25,50]), "YES")
    def test_tickets_should_return_NO(self):
        self.assertEqual(tickets([25,25,100]), "NO")


if __name__ == '__main__':
    unittest.main()
```
* 잔돈이 50, 75 일 때 두가지 case로 나누어 작성했다.

## 다른사람의 풀이방법

### Best practice
```python
def tickets(people):
    till = {100.0:0, 50.0:0, 25.0:0}
    for paid in people:
        till[paid] += 1
        change = paid-25.0
        
        for bill in (50,25):
            while (bill <= change and till[bill] > 0):
                till[bill] -= 1
                change -= bill

        if change != 0:
            return 'NO'
        
    return 'YES'
```
* 내가 case를 나누어 작성한 부분을 while문을 이용하여 간결하게 작성했다. 

### Clever
```python
def tickets(a):
    n25 = n50 = n100 = 0
    for e in a:
        if   e==25            : n25+=1
        elif e==50            : n25-=1; n50+=1
        elif e==100 and n50>0 : n25-=1; n50-=1
        elif e==100 and n50==0: n25-=3
        if n25<0 or n50<0:
            return 'NO'
    return 'YES'
```
* 내 방식과 비슷하지만 훨씬 간결하다. 

## 배운점
* 문제해결방법?

## 반성할점
* 간단할 줄 알았는데 생각보다 어려웠다. best practice를 보니 간단하게 할 수 있었는데 라는 생각도 든다. 많이 풀어봐야겠다.

## Action Item
* 효율적인 프로그램 작성.