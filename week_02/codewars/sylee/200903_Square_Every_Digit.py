# 1
def square_digits(num):
    return int("".join(str(int(x) ** 2) for x in str(num)))

#2
def square_digits(num):
    return int("".join(str(x ** 2) for x in map(int, str(num))))

#3
def square_digits(num):
    list_square = [int(x) ** 2 for x in str(num)]
    return int(("{}" * len(list_square)).format(*list_square))