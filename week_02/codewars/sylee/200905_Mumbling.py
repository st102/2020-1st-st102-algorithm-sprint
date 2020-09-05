def accum(string):
    return "-".join(
        element.upper() + element * index
        for index, element in enumerate(string.lower())
    )