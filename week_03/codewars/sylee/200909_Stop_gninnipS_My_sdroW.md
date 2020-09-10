# Stop gninnipS My sdroW!

## 문제설명

> 받은 문자열중 길이가 5이상의 단어는 거꾸로 만들어 출력한다.

## 나의 풀이 방법

 ```python
def spin_words(sentence):
    words = sentence.split()
    return " ".join(
        [
            element if len(element) < 5 else "".join(list(reversed(element)))
            for element in words
        ]
    )


class Test_spin_words(unittest.TestCase):
    def test_length_of_word_is_less_than_five_when_given_only_one_word(self):
        self.assertEqual(spin_words("1234"), "1234")

    def test_length_of_word_is_five_or_above_when_given_only_one_word(self):
        self.assertEqual(spin_words("12345"), "54321")

    def test_length_of_word_is_less_than_five_when_given_more_than_one_word(self):
        self.assertEqual(spin_words("123 456 7890"), "123 456 7890")

    def test_length_of_word_is_five_or_above_when_given_more_than_one_word(self):
        self.assertEqual(spin_words("123 456 78910"), "123 456 01987")

 ```

> 1.  문자열이 단어 하나일 때
>    - 길이가 5 이하일 때
>    - 길이가 5 이상일 때
> 2.  문자열이 단어 둘 이상일 때
>    - 모든 단어의 길이가 5 이하일 때
>    - 단어중 길이가 5이상인 단어가 있을 때

>위와 같이 테스트를 구성했다.




## 다른 사람의 풀이 방법

```python
# Best Practices 1
def spin_words(sentence):
    return " ".join([x[::-1] if len(x) >= 5 else x for x in sentence.split(" ")])
```

> `x[::-1]`로 사용했다. 굳이 `reversed()`를 사용해 다시 `list`로 변환할 필요가 없었다.



## 배운 점

>  index 이용하기.



## 반성할 점

> 이번엔 조건을 잘 나눈 것 같다.



## Action Item

> 