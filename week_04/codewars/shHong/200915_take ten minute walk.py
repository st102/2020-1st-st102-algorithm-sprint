import unittest


WALK_TIME = 10
NORTH, SOUTH, WEST, EAST = 'n', 's', 'w', 'e'
def is_valid_walk(walk):
    x, y = 0, 0
    for c in walk:
        if c == NORTH: y += 1
        elif c == SOUTH: y -= 1
        elif c == WEST: x += 1
        elif c == EAST: x -= 1
    return True if x == 0 and y == 0 and len(walk) == WALK_TIME else False


class TestIsValidWalk(unittest.TestCase):
    def test_is_valid_walk_with_10_minutes_walk(self):
        self.assertEqual(is_valid_walk(['n','s','n','s','n','s','n','s','n','s']), True)
    def test_is_valid_walk_with_not_10_minutes_walk(self):
        self.assertEqual(is_valid_walk(['n','s']), False)
    def test_is_valid_walk_with_no_return_to_startpoint(self):
        self.assertEqual(is_valid_walk(['n','n','n','s','n','s','n','s','n','s']), False)


if __name__ == '__main__':
    unittest.main()