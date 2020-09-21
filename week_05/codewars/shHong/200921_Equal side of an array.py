import unittest


def find_even_index(arr):
    for i in range(len(arr)):
        if sum(arr[:i]) == sum(arr[i+1:]):
            return i
    return -1


class TestFindEvenIndex(unittest.TestCase):
    def test_find_even_index_should_return_true_value(self):
        self.assertEqual(find_even_index([1,2,3,4,3,2,1]),3)
        self.assertEqual(find_even_index([20,10,30,10,10,15,35]),3)

    def test_find_even_index_should_return_false_value(self):
        self.assertEqual(find_even_index([1,2,3,4,5,6]),-1)


if __name__ == '__main__':
    unittest.main()