import unittest


YES = "YES"
NO = "NO"
TICKET_PAY = 25

def tickets(people):
    change = {25:0, 50:0, 100:0}
    for n in people:
        if n != TICKET_PAY:
            returnchange = n - TICKET_PAY
            if returnchange == 25:
                if change[25] < 1:
                    return NO
                else:
                    change[25] -= 1
            elif returnchange == 50:
                if change[50] < 1:
                    if change[25] < 2:
                        return NO
                    else:
                        change[25] -= 2
                else:
                    change[50] -= 1
            elif returnchange == 75:
                if change[50] >= 1 and change[25] >= 1:
                    change[50] -= 1
                    change[25] -= 1
                elif change[25] >= 3:
                    change[25] -= 3
                else:
                    return NO
        change[n] += 1
    return YES
                     

class TestTickets(unittest.TestCase):
    def test_tickets_should_return_YES(self):
        self.assertEqual(tickets([25,25,50]), "YES")
    def test_tickets_should_return_NO(self):
        self.assertEqual(tickets([25,25,100]), "NO")


if __name__ == '__main__':
    unittest.main()