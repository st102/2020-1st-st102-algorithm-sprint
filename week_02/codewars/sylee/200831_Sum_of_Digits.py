def digital_root(n):
    result_a = sum(int(x) for x in str(n))
    return result_a if result_a < 10 else digital_root(result_a)