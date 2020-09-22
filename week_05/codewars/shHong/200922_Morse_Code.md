# 05주차 Morse code - python

## 문제 설명
* 모스부호 해독

## 풀이방법
```python
import unittest


MORSE_CODE = {'.-': 'A', '-...': 'B', '-.-.': 'C', '-..': 'D', '.': 'E', '..-.': 'F', '--.': 'G', '....': 'H', '..': 'I', '.---': 'J', '-.-': 'K', '.-..': 'L', '--': 'M', '-.': 'N', '---': 'O', '.--.': 'P', '--.-': 'Q', '.-.': 'R', '...': 'S', '-': 'T', '..-': 'U', '...-': 'V', '.--': 'W', '-..-': 'X', '-.--': 'Y', '--..': 'Z', '-----': '0', '.----': '1', '..---': '2', '...--': '3', '....-': '4', '.....': '5', '-....': '6', '--...': '7', '---..': '8', '----.': '9', '.-.-.-': '.', '--..--': ',', '..--..': '?', '.----.': "'", '-.-.--': '!', '-..-.': '/', '-.--.': '(', '-.--.-': ')', '.-...': '&', '---...': ':', '-.-.-.': ';', '-...-': '=', '.-.-.': '+', '-....-': '-', '..--.-': '_', '.-..-.': '"', '...-..-': '$', '.--.-.': '@', '...---...': 'SOS'}


def decodeMorse(morse_code):
    return "".join(MORSE_CODE[c] if c != '/' else ' ' for c in morse_code.strip().replace('   ', ' / ').split())


class TestDecodeMorse(unittest.TestCase):
    def test_decodeMorse_with_no_strip(self):
        self.assertEqual(decodeMorse('.... . -.--   .--- ..- -.. .'), 'HEY JUDE')

    def test_decodeMorse_with_strip(self):
        self.assertEqual(decodeMorse('       .   .'), 'E E')


if __name__ == '__main__':
    unittest.main()
    
```
* 공백처리가 힘들었다. '   '을 ' / '로 변환해서 띄어쓰기일 경우를 구분했다.
* 앞뒤로 공백이 삽입된 경우 ```strip()```을 이용하여 제거했다.

## 다른사람의 풀이방법

### Best practice
```python
def decodeMorse(morseCode):
    return ' '.join(''.join(MORSE_CODE[letter] for letter in word.split(' ')) for word in morseCode.strip().split('   '))
```
* 먼저 띄어쓰기로 나눈 후 모스부호 해독을 했다. 이 방법이 더 적절한 것 같다.

### Clever

* Best practice.

## 배운점
* .

## 반성할점
* 생각보다 시간이 꽤 걸렸다. 문자열은 자신있다 생각 했는데 연습이 더 필요할 것 같다.

## Action Item
* 효율적인 프로그램 작성.