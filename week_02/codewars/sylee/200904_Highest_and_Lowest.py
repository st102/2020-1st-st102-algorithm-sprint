def high_and_low(numbers):
    list_of_number = [x for x in map(int, numbers.split())]
    return "{} {}".format(max(list_of_number), min(list_of_number))