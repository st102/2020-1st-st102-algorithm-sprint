def high_and_low(numbers):
    nums = list(map(int, numbers.split()))
    return "{} {}".format(max(nums), min(nums))