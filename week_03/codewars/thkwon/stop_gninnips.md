# Stop gninnipS My sdroW!

## 문제 설명

* 띄어쓰기로 이루어진 string 단어를 나누고 5이상일 경우는 문자를 뒤집는다



## 나의 풀이 방법

```python
import unittest

MAX_WORD_LENGTH_FOR_REVERSING = 5


def spin_words(sentence):
    words = sentence.split()
    return " ".join(
        element if len(element) < 5 else "".join(list(reversed(element)))
        for element in words
    )
    
    
class TestSpinWords(unittest.TestCase):
    def test_spin_words_with_given_sentence_has_all_of_word_length_is_equal_less_than_5(self):
        self.assertEqual(spin_words('Hello World'), 'olleH dlroW')

    def test_spin_words_with_given_sentence_has_all_of_word_length_is_greater_than_5(self):
        self.assertEqual(spin_words('abcdefz bcdefgz cdefghiz'), 'zfedcba zgfedcb zihgfedc')

    def test_spin_words_with_given_sentence_has_word_length_is_greater_than_5_or_not(self):

        self.assertEqual(spin_words('olleH bcdefgz dlroW'), 'Hello zgfedcb World')

```

*  map() 을 이용해서, 검사하려는 list를 `len` 을 기준으로 만들어준 후, 그 중 최소 값을 리턴하였다.
*  테스트는 어떤 엣지케이스가 없었기 때문에 common 한 케이스에 대해서 테스트 해도 된다고 판단하였고, 메소드 명도 common하게 지어주었다.

## 다른 사람의 풀이 방법

* ### Clever

  ```python
  import re
  
  def spin_words(sentence):
    # Your code goes here
      return re.sub(r"\w{5,}", lambda w: w.group(0)[::-1], sentence)
  ```
  
  * 풀이 중에 딱히 눈에 띄는 코드는 없었고, 위의 정규표현식을 활용한 풀이는 레퍼런스용으로 남겨두고 활용하면 좋을 것 같다


## 배운 점

*   위 문제를 풀 때, 정규표현식을 활용해서도 풀 수 있음
*   표준적인 generator expression의 활용을 복습할 수 있었음

## 반성할 점

*   없음

## Action Item

*   정규 표현식을 조금씩 익혀두자.

