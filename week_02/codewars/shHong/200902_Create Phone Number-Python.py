def create_phone_number(n):
    return "({0}) {1}-{2}".format(join_(n[:3]),join_(n[3:6]),join_(n[6:]))


def join_(s):
    return "".join(map(str, s))