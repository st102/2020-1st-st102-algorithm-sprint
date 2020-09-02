# 02주차 Who likes it - Python

## 풀이방법
```python
def likes(names):
    if len(names) == 0:
        ans = "no one likes this"
    elif len(names) == 1:
        ans = "{0} likes this".format(names[0])
    elif len(names) == 2:
        ans = "{0} and {1} like this".format(names[0], names[1])
    elif len(names) == 3:
        ans = "{0}, {1} and {2} like this".format(names[0], names[1], names[2])
    else:
        ans = "{0}, {1} and {2} others like this".format(names[0], names[1], len(names) - 2)
    return ans
```
* format()을 이용하여 문자열을 저장했다.

## 다른사람의 풀이방법

### Best practice
```python
def likes(names):
    n = len(names)
    return {
        0: 'no one likes this',
        1: '{} likes this', 
        2: '{} and {} like this', 
        3: '{}, {} and {} like this', 
        4: '{}, {} and {others} others like this'
    }[min(4, n)].format(*names[:3], others=n-2)
```
* dictionary와 *list를 이용하여 작성했다.
* 다른 방법이 없을 줄 알았는데 이런 방법도 있어서 참신하다.
* clever & best code.

## 배운점
* dictionary, format()의 다양한 사용법.

## 반성할점
* 없는 것 같다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.