def disemvowel(string):
    return "".join(s for s in string if s not in "aeiouAEIOU")