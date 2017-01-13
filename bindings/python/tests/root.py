from cadna import double_st, nb_significant_digit
a = double_st(0.3)
b = double_st(2.1)
c = double_st(3.657)
d = b*b-4*a*c
print nb_significant_digit(d)
