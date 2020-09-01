def digital_root(n):
    number = str(n)
    while len(number) != 1:
        number = str(sum(int(num) for num in number))
    return int(number)