# Alphabet

## 문제 설명

*   Digital Root 에 대한 결과값을 리턴해라.
    *   Digital root는 어떤 숫자의 각 digit를 재귀적으로 합한 것을 말한다.

## 나의 풀이 방법

```python
import unittest


ALPHABET_COUNT = 26
LOWER_A_ASCII_NUMBER = 97


def alphabet(lower_case_string):
    alphabet_position_list = [-1] * 26

    for char in lower_case_string:
        alphabet_position_list[ord(char) - LOWER_A_ASCII_NUMBER] = lower_case_string.index(char)

    return ' '.join(map(str, alphabet_position_list))
    
    
class TestAlphabet(unittest.TestCase):
    def test_alphabet(self):
        self.assertEqual(
            alphabet('baekjoon'),
            '1 0 -1 -1 2 -1 -1 -1 -1 4 3 -1 -1 7 5 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1',
        )

```

*   최초 `-1` 로 채워진 배열을 만들고,
*   주어진 string을 받아서, string 길이만큼 루프를 돌면서, 해당하는 알파벳 자리에 주어진 string에서의 index 값을 채워 넣으면 된다.

## 다른 사람의 풀이 방법

* 백준 온라인의 최대 단점은 다른 사람의 답을 온라인에서 직접 검색해야하는 것인데, 솔직히 말해서 파이썬 코드 작성의 수준이 많이 떨어져서 굳이 여기에 적고 배운점과 반성할 점을 쓸 필요가 있을까 라는 생각이 들었다..
  * 물론 나의 풀이가 베스트 프랙티스라는 것은 아님
  * 내 코드 보다 잘 짠 코드를 보고 배우고 싶은데.. 그런 코드를 찾기 힘들었음..
* 이런 점을 봤을 때, 백준 플랫폼을 선택한 것은 조금 잘못된 선택일 수도 있을 것 같다.

## 배운 점

*   이 문제는 매우 쉬운 문제라서 딱히 배울 내용은 없는 것 같다
*   파이썬의 관점에서는 문자열의 char index를 구하는 메소드 혹은 아스키코드 값을 활용하는 수준 정도 로 볼 수 있을 것 같다.

## 반성할 점

*   문제에 대한 반성은 없다.

## Action Item

*   없음

