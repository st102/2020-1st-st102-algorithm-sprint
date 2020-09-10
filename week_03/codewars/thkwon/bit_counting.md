# bit counting

## 문제 설명

* 주어진 integer number 를 binary로 고친 후, 1의 개수를 리턴한다



## 나의 풀이 방법

```python
import unittest

ONE = '1'


def count_bits(number):
    return bin(number).count(ONE)
    
    
class TestCountBits(unittest.TestCase):
    def test_count_bits_should_return_0_when_given_n_is_0(self):
        self.assertEqual(count_bits(0), 0)

    def test_count_bits_with_common_case(self):
        self.assertEqual(count_bits(7), 3)

```

*  파이썬에서는 각 진수 마다 변환할 수 있는 내장 함수를 지원한다.
*  Bin 이라는 내장함수를 이용하고, count 메소드를 활용하여, 문자열 내 1의 개수를 리턴해주도록 하였다.

## 다른 사람의 풀이 방법

* ### Clever

  ```python
  def countBits(n):ㄹ
      total = 0
      while n > 0:
          total += n % 2
          n >>= 1
      return total
  ```
  
  * ```python
      x >> y
      Returns x with the bits shifted to the right by y places. This is the same as //'ing x by 2**y.
      ```
  
  * 아마도 파이썬이 아닌, 다른 언어는 위와 같은 방식의 풀이를 사용했을 수도 있을 것 같다.
  
  * y bit 만큼 shift 했을 때 값을 리턴해서 0이면 루프를 종료하고, 그때 까지의 나머지 값들의 합을 리턴하는 방식


## 배운 점

*   위의 방법 이외에도, 나머지와 비트연산을 이용한 다양한 풀이있었고, 이 풀이들에 대해서 알 수 있었다

## 반성할 점

*   bit 연산자의 활용의 측면에서 사실 잘 모른다
*   그래서 관련된 작업이 있을 때, 매번 레퍼런스를 찾아보는데, 조금씩이라도 레퍼런스 보지 않고 바로 생각해서 적용할 수 있도록 노력할 필요가 있다

## Action Item

*   bit 연산 관련 문제가 나왔을 때, 그때그때 정리해 두자.
