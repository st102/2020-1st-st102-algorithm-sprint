import unittest


def accum(string):
    return '-'.join((char * index).capitalize() for index, char in enumerate(string, 1))
    
    
class TestAccum(unittest.TestCase):
    def test_accum_common_case_1(self):
        self.assertEqual(accum('ZpglnRxqenU'), 'Z-Pp-Ggg-Llll-Nnnnn-Rrrrrr-Xxxxxxx-Qqqqqqqq-Eeeeeeeee-Nnnnnnnnnn-Uuuuuuuuuuu')

    def test_accum_common_case_2(self):
        self.assertEqual(accum('NyffsGeyylB'), "N-Yy-Fff-Ffff-Sssss-Gggggg-Eeeeeee-Yyyyyyyy-Yyyyyyyyy-Llllllllll-Bbbbbbbbbbb")
