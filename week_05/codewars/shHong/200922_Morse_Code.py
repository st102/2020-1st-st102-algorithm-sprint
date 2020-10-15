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
    