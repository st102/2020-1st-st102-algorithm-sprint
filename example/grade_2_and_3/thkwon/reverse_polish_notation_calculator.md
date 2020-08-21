# Reverse polish notation calculator

## 문제 설명

 [Reverse Polish notation](http://en.wikipedia.org/wiki/Reverse_Polish_notation) 문제이다

* 대개는 `1 + 2 = 3` 이렇게 표현되는데, `1 2 + = 3 ` 이렇게 표현되는 것을 말한다.  



## 나의 풀이 방법

```python
# 최초 풀이

import unittest
import operator
from collections import deque

OPERATORS = {'+', '-', '*', '/'}


def calc(expr):

    if not expr:
        return 0

    expr_list = expr.split()
    if len(expr_list) == 1:
        return (int(expr_list[0])
                if isinstance(expr_list[0], int)
                else float(expr_list[0]))

    expr_num_deque = deque()
    for idx, ele in enumerate(expr_list):
        if ele in OPERATORS:
            prev = expr_num_deque.pop()
            prev_prev = expr_num_deque.pop()
            expr_num_deque.append(_get_result_by_notation(ele, prev, prev_prev))
        else:
            expr_num_deque.append(int(ele))

    return expr_num_deque[0]
```



```python
# 제출 후 수정한 코드

from operator import add, floordiv, mul, sub
import unittest

OPERATIONS = {"+": add, "-": sub, "*": mul, "/": floordiv}


def calc(expr):
    stack = []
    for ele in expr.split():
        if ele in OPERATIONS:
            prev = stack.pop()
            prev_prev = stack.pop()
            stack.append(OPERATIONS[ele](prev_prev, prev))
        else:
            stack.append(float(ele))

    return (stack and stack[0]) or 0
```

* stack을 이용하여서 문제를 풀었다.
* stack 을 만들고 숫자이면 stack에 넣고, opertor이면 넣은 숫자 중 2개를 빼내서 operator에 맞게 계산하도록 하여 문제를 풀었다.



```python
# 테스트

class TestCalc(unittest.TestCase):
    def test_should_return_0_when_given_expr_is_empty_string(self):
        expr = ""
        actual = calc(expr)
        self.assertEqual(actual, 0)

    def test_calc_with_only_number_not_notation(self):
        expr = "3"
        actual = calc(expr)
        self.assertEqual(actual, 3)

    def test_calc_with_only_float_number_not_notation(self):
        expr = "3.5"
        actual = calc(expr)
        self.assertEqual(actual, 3.5)

    def test_calc_with_only_two_numbers_and_one_noation(self):
        expr = "1 3 +"
        actual = calc(expr)
        self.assertEqual(actual, 4)

    def test_calc_with_only_two_numbers_and_one_noation_is_plus(self):
        expr = "1 3 +"
        actual = calc(expr)
        self.assertEqual(actual, 4)

    def test_calc_with_only_two_numbers_and_one_noation_is_minus(self):
        expr = "1 3 -"
        actual = calc(expr)
        self.assertEqual(actual, -2)

    def test_calc_with_only_two_numbers_and_one_noation_is_multiply(self):
        expr = "1 3 *"
        actual = calc(expr)
        self.assertEqual(actual, 3)

    def test_calc_with_only_two_numbers_and_one_noation_is_division(self):
        expr = "10 2 /"
        actual = calc(expr)
        self.assertEqual(actual, 5)

    def test_calc_with_multiple_numbers_and_multiple_notations(self):
        expr = "5 1 2 + 4 * + 3 -"
        actual = calc(expr)
        self.assertEqual(actual, 14)
```





## 다른 사람의 풀이 방법

### Best Practice for me

```python
from operator import add, sub, mul, truediv

ops = {'+': add, '-': sub, '*': mul, '/': truediv}

def calc(expr):
    stack = []
    for x in expr.split():
        if x in '+-*/':
            b, a = stack.pop(), stack.pop()
            x = ops[x](a, b)
        stack.append(float(x))
    return (stack or [0]).pop()
```

* 역시나 정민이 코드인데, 내가 작성한 코드와 비슷한데 훨씬더 코드가 깔끔한 느낌이 든다.

### Best Practice

```python
import operator

def calc(expr):
    OPERATORS = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.truediv}
    stack = [0]
    for token in expr.split(" "):
        if token in OPERATORS:
            op2, op1 = stack.pop(), stack.pop()
            stack.append(OPERATORS[token](op1,op2))
        elif token:
            stack.append(float(token))
    return stack.pop()
```

* 이게 Best Practice 인데, 사실 좀 수정할 부분도 보인다
* 내 코드와 거의 비슷한데, 상수를 함수 밖으로 빼놓은다던지, split할 때 굳이 (" ")를 할필요가 없다던지의 코드리뷰 거리가 보인다

### Clever

```python
operator = set(['+', '-', '*', '/'])

def calc(expr):
    stack = list()
    for c in expr.split():
        if c in operator : 
            first = stack.pop()
            second = stack.pop()
            stack.append(str(eval(second + c + first)))
        else : stack.append(c)
    return eval(stack.pop()) if stack else 0
```

* 이 코드도 거의 비슷한데, 코드리뷰 포인트가 몇가지 있다
  * stack을 list()로 생성할 필요가 굳이 없다.
  * operator 를 셋으로 만들 때, 굳이 리스트로 만들어서 다시 set을 만들 필요가 없고, 상수로 처리할 것 이였다면, `operator` 를 대문자로 써주어야 한다.
  * `eval` 을 사용하였는데, 특별한 경우가 아니라면 왠만하면 쓰지 않는 것이 좋을 것 같다.



## 배운 점

* stack 관련 문제는 유형이 조금씩 다른데 읽어보면, stack을 사용해야할 것 같은 느낌이 난다. 이 문제도 그러했고, 스택관련 문제 유형 하나를 더 배웠다.



## 반성할 점

* 처음에 문제 접근 할 때는 stack 쓸 생각을 못하였다가, 최초 테스트가 한번 틀리고 나서 이 문제는 stack을 써야하는 것 이라고 깨닫게 되었다. 앞으로 비슷한 문제가 나오면 바로 stack으로 문제를 풀 수 있도록 하자
* 첫번째 제출을 할 때, operator if 문을 쓰는 부분에서 dict 로 개선할 수 있는 것에 대해서 놓쳤다. 간단하게 dict로 표현된다면, 구구절절이 if 문을 사용하지 말고 해결해보도록 하자.



## Action Item

* stack 문제 유형에 대해서 파악하고 관련 문제가 나오면 바로 바로 적용
  * Postfix operator 문제
  * 괄호 짝 맞춤 문제 등등


