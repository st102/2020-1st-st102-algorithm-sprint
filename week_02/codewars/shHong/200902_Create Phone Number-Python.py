def create_phone_number(n):
    return "({0}) {1}-{2}".format(join(n[:3]),join(n[3:6]),join(n[6:]))
def join(s):
    return "".join(map(str, s))