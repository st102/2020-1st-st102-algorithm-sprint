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

