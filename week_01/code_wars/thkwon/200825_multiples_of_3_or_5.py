import unittest


def solution(number):

    def is_multiples_of_3_or_5(element):
        return element % 3 == 0 or element % 5 == 0

    return sum(element for element in range(3, number) if is_multiples_of_3_or_5(element))
    
    
class TestSolution(unittest.TestCase):
    def test_solution_should_return_10_with_number_is_10(self):
        self.assertEqual(solution(10), 23)

    def test_solution_should_return_0_with_number_is_0(self):
        self.assertEqual(solution(0), 0)

    def test_solution_should_return_1_with_number_is_0(self):
        self.assertEqual(solution(1), 0)

    def test_solution_should_return_2_with_number_is_0(self):
        self.assertEqual(solution(2), 0)