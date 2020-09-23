import unittest
import re


def to_camel_case(text):
    textlist = re.split('-|_', text)
    return textlist[0] + "".join(txt.title() for txt in textlist[1:])


class TestToCamelCase(unittest.TestCase):
    def test_to_camel_case_with_hyphen_string(self):
        self.assertEqual(to_camel_case("hello-world-hello"), "helloWorldHello")

    def test_to_camel_case_with_underbar_string(self):
        self.assertEqual(to_camel_case("hello_world_hello"), "helloWorldHello")

    def test_to_camel_case_with_mixed_case_string(self):
        self.assertEqual(to_camel_case("hello_world-hello"), "helloWorldHello")


if __name__ == '__main__':
    unittest.main()