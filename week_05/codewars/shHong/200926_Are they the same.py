import unittest


def comp(array1, array2):
    if array1 == [] or array2 == []:
        return True if array1 == array2 else False
    
    for n1, n2 in zip(sorted(array1, key = abs), sorted(array2, key = abs)):
        if n1 ** 2 != n2:
            return False
    return True   


class TestComp(unittest.TestCase):
    def test_comp_should_return_True(self):
        self.assertEqual(comp([1,2,3,4], [1,4,9,16]), True)
    def test_comp_with_empty_array_should_return_False(self):
        self.assertEqual(comp([], [1]), False)
    def test_comp_with_negative_should_return_True(self):
        self.assertEqual(comp([-1,-2,-3,-4], [1,4,9,16]), True)


if __name__ == '__main__':
    unittest.main()