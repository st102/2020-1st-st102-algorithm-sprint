import unittest

MAX_INDEX = 4
MAX_KWARGS_COUNT = 3

NO_ONE_LIKES = "no one likes this"
ONLY_ONE_LIKES = "{} likes this"
TWO_LIKES = "{} and {} like this"
THREE_LIKES = "{}, {} and {} like this"
OVER_FOUR_LIKES = "{}, {} and {rest} others like this"


def likes(names):
    length_of_names = len(names)

    return {
        0: NO_ONE_LIKES,
        1: ONLY_ONE_LIKES,
        2: TWO_LIKES,
        3: THREE_LIKES,
        4: OVER_FOUR_LIKES,
    }[min(length_of_names, MAX_INDEX)].format(*names[:MAX_KWARGS_COUNT], rest=length_of_names - 2)


class TestLikes(unittest.TestCase):
    def test_likes_no_one(self):
        self.assertEqual(likes([]), "no one likes this")

    def test_likes_only_one(self):
        self.assertEqual(likes(["Peter"]), "Peter likes this")

    def test_likes_two(self):
        self.assertEqual(likes(["Jacob", "Alex"]), "Jacob and Alex like this")

    def test_likes_three(self):
        self.assertEqual(likes(["Max", "John", "Mark"]), "Max, John and Mark like this")

    def test_likes_over_four(self):
        self.assertEqual(likes(["Alex", "Jacob", "Mark", "Max"]), "Alex, Jacob and 2 others like this")

    def test_likes_over_five(self):
        self.assertEqual(likes(["Alex", "Jacob", "Mark", "Max", "Kwon"]), "Alex, Jacob and 3 others like this")
