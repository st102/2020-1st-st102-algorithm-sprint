def find_short(s):
    return min(len(i) for i in s.split())


class Test_Short(unittest.TestCase):
    def test_shortest_is_three(self):
        self.assertEqual(
            find_short("bitcoin take over the world maybe who knows perhaps"), 3
        )

    def test_shortest_is_two(self):
        self.assertEqual(find_short("Lets all go on holiday somewhere very cold"), 2)

    def test_shortest_is_one(self):
        self.assertEqual(
            find_short("i want to travel the world writing code one day"), 1
        )
