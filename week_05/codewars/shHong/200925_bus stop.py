import unittest


def number(bus_stops):
    return sum((stop[0] - stop[1]) for stop in bus_stops)
        

class TestNumber(unittest.TestCase):
    def test_number(self):
        self.assertEqual(number([[3,0],[9,1],[4,10],[12,2],[6,1],[7,10]]),17)


if __name__ == '__main__':
    unittest.main()