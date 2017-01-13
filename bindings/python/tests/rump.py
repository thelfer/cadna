from cadna import numericalnoise, nb_significant_digit
from cadna import double_st as real
try:
    import unittest2 as unittest
except ImportError:
    import unittest

class RumpTest(unittest.TestCase):

    def test_pass(self):

        rump = lambda x,y: 9*x*x*x*x-y*y*y*y+2*y*y
        x = real(10864)
        y = real(18817)
        v = rump(x,y)
        self.assertTrue(numericalnoise(v))
        self.assertTrue(nb_significant_digit(v)==0)
        
if __name__ == '__main__':
    unittest.main()
