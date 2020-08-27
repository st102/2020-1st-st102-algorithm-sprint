from functools import reduce
def find_it(xs):
    return reduce(lambda x, y: x ^ y, xs)

print(find_it([5,4,3,2,1,5,4,3,2,10,10]))