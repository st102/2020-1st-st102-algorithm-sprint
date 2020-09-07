# List_Filtering

## 문제 설명

*   리스트에서 숫자만 추출하기

## 나의 풀이 방법

```python
import re

def filter_list(l):
    relist=[]
    for filtering in l:
        if(isinstance(filtering,int)):
            relist.append(filtering)
    return relist

class TestListFiltering(unittest.TestCase):
    def test_list_filterng(unittest.TestCase):
        self.assert_equals(filter_list([1,2,'a','b',3,4,'c',5])),[1,2,3,4,5])

    def test_list_filterng_many_times(unittest.TestCase):
        self.assert_equals(filter_list([0,'a','0','b'])),[0])

    def test_list_filterng_long_long(unittest.TestCase):
        self.assert_equals(filter_list(['asdfasdf','123','12532','123123', 'longlong'])),[123,12532,123123])
```

*   relist 리턴할 리스트를 만들고 for문으로 제시된 리스트를 돌며 리스트에 filtering을 넣는다.
*   isinstance를 사용하여 int인 부분을 찾는다.

## 다른 사람의 풀이 방법

* ### Best Practice & Clever

```python
def filter_list(l):
    'return a new list with the strings filtered out'
    return [i for i in l if not isinstance(i, str)]
```

*    return에서 리스트를 만들어 그안에 string을 제외하고 받을 수 있도록하였다.
*   이 방법이 좋다고 생각되는 이유는 나는 int만을 걸렀는데  저분의 풀이로는 문자를 
    제외한 숫자들은 모두 받을 수 있게된다.

## 배운 점

*   isinstance라는 함수에 대해서 알게되었다.

## 반성할 점

*   int만 생각하고 코드를 작성하였다. tdd를 작성할 때 생각 못한점이 후회스럽다.

## Action Item

*   다양하게 생각하자!

