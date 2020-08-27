def find_it(seq):
    return [element for element in set(seq) if seq.count(element) % 2 != 0][0]
