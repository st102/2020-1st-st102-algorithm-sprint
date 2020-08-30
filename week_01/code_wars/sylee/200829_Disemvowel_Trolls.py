def disemvowel(string):
    string = list(string)

    for element in "aeiouAEIOU":
        while element in string:
            string.remove(element)
    string = "".join(string)
    return string
