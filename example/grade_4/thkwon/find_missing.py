def find_missing(sequence):
    def get_last_by_diff(diff, last_value):
        if diff < 0:
            last_value -= 1
        else:
            last_value += 1
        return last_value

    first, last = sequence[0], sequence[-1]
    diff = (last - first) // len(sequence)

    last = get_last_by_diff(diff, last)
    return sum(range(first, last, diff)) - sum(sequence)
