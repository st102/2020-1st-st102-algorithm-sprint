import unittest


def dirReduc(arr):
    if arr == []:
        return []
    stack = []
    for i in range(len(arr)):
        if stack == []:
            stack.append(arr[i])
        elif stack[-1] == 'NORTH':
            if arr[i] == 'SOUTH':
                stack.pop()
            else:
                stack.append(arr[i])
        elif stack[-1] == 'SOUTH':
            if arr[i] == 'NORTH':
                stack.pop()
            else:
                stack.append(arr[i])
        elif stack[-1] == 'EAST':
            if arr[i] == 'WEST':
                stack.pop()
            else:
                stack.append(arr[i])
        elif stack[-1] == 'WEST':
            if arr[i] == 'EAST':
                stack.pop()
            else:
                stack.append(arr[i])
    return stack


class TestDirReduce(unittest.TestCase):
    def test_dir_reduce(self):
        self.assertEqual(dirReduc(["NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"]), ['WEST'])


if __name__ == '__main__':
    unittest.main()
    