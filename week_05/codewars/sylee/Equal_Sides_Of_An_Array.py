import unittest


def find_even_index(arr):
    find_index = [
        index
        for index in range(len(arr))
        if (sum(arr[:index]) == sum(arr[index + 1 :]))
    ]
    return find_index[0] if find_index else -1


class TestEqualSide(unittest.TestCase):
    def test_index_exist(self):
        self.assertEqual(find_even_index([1, 2, 3, 4, 3, 2, 1]), 3,)

    def test_index_not_exist(self):
        self.assertEqual(find_even_index(list(range(1, 100))), -1)

    def test_all_list_elem_is_0(self):
        self.assertEqual(find_even_index([0, 0, 0, 0, 0]), 0)