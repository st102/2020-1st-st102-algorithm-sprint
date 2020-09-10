# 02주차 Spin words - python

## 문제 설명
* 입력받은 문자열 중 길이가 5 이상인 단어를 뒤집는다.

## 풀이방법
```python
import unittest


def spin_words(sentence):
    return " ".join(word[::-1] if len(word) >= 5 else word for word in sentence.split())


class TestSpinWords(unittest.TestCase):
    def test_spin_words_with_words_length_under_4(self):
        self.assertEqual(spin_words("Hong se hwa"), "Hong se hwa")
    def test_spin_words_with_words_length_over_5(self):
        self.assertEqual(spin_words("Hello World icedAmericano drink JwabJwab"),
         "olleH dlroW onaciremAdeci knird bawJbawJ")
    def test_spin_words_with_words_length_mix(self):
        self.assertEqual(spin_words("Hong se hwa JJANG"), "Hong se hwa GNAJJ")


if __name__ == "__main__":
    unittest.main()
```

* Given: 4이하의 단어의 문자열, 5이상의 단어의 문자열, 둘을 섞었을 경우의 문자열
* When: 5이상의 단어만 뒤집는다.
* then: 길이가 5 이상인 단어만 뒤집혔다.

## 다른사람의 풀이방법

### Best practice
```python
def spin_words(sentence):
    # Your code goes here
    return " ".join([x[::-1] if len(x) >= 5 else x for x in sentence.split(" ")])
```
* 나와 같은 코드.
* clever는 따로 정하지 않았다.

## 배운점
* given when then을 이용한 테스트코드 작성

## 반성할점
* 이번엔 테스트가 문서의 역할도 하며 기능 설명이 명확하다 생각해서 반성할 점은 없다 생각한다.

## Action Item
* 다른 코드를 보며 python스럽게 짜보기.
* expression을 최대한 활용.
* 최적의 시간을 갖는 코드를 짜도록 노력하기.
* 다양한 자료구조 사용해보기.
* 다양한 test 작성해보기.