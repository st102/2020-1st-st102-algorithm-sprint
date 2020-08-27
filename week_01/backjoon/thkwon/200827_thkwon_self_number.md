# Self Number

## 문제 설명

*   셀프 넘버를 구해서, 구하는 즉시 한줄로 출력한다.

## 나의 풀이 방법

```python
def solution():

    def get_no_self_number(element):
        string_element = str(element)
        no_self_number = element
        for number in range(len(string_element)):
            no_self_number += int(string_element[number])
        return no_self_number

    no_self_number_set = set()

    for index in range(1, 10000 + 1):
        if index not in no_self_number_set:
            print(index)
        no_self_number_set.add(get_no_self_number(index))


if __name__ == '__main__':
    solution()

```

* 주어진 수 10000 에 대해서, 각 루프 마다 검사를 하면서, self_number가 아닌 수로 판정된 집합에 없으면, 셀프넘버로 보고 출력한다
* `get_no_self_number` 라는 내부 함수를 만들어서, 루프 마다 계산을 하고, 집합에 추가 시켜주었다.
* 결론적으로, 셀프숫자가 아닌 수를 제외한 모든 수는 셀프 숫자이기 때문에, 셀프 숫자가 아닌 수를 구한 후 나머지를 쭉 출력하는 방식을 사용하였다.

## 다른 사람의 풀이 방법

* 구글에서 검색했을 때 나오는 10개정도의 블로그를 보았는데, 이 문제와 관련해서 파이썬 코드 중에 내가 참고할 만큼 괜찮은 코드는 없었다(백준은.. 이게 너무 단점..)



## 배운 점

*   셀프 넘버에 대해서 처음 알게되었다.
*   문제 난이도가 높지 않아서 그리 배울점은 없었다

## 반성할 점

* 셀프 넘버에 대한 개념을 처음에 듣고, 차근차근히 문제를 풀어나갔긴 했지만, 중간에 계산하는 과정에서 당황한 부분이 있었다
* 앞으로 새로운 개념이 나올 때, 당황하지 말고 정의를 잘 읽어보고 내가 풀고자 하는 문제 그대로를 구현 하면 되는 것이라고 생각하고 차근차근 풀어나가자

## Action Item

*   비슷한 문제를 풀어가면서, 이러한 숫자와 관련된 예제에 익숙해져야곘다