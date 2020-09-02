def create_phone_number(n):
    return "({}{}{}) {}{}{}-{}{}{}{}".format(*n[:10])