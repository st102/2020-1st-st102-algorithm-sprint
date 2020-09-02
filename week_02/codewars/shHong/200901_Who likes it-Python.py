def likes(names):
    if len(names) == 0:
        ans = "no one likes this"
    elif len(names) == 1:
        ans = "{0} likes this".format(names[0])
    elif len(names) == 2:
        ans = "{0} and {1} like this".format(names[0], names[1])
    elif len(names) == 3:
        ans = "{0}, {1} and {2} like this".format(names[0], names[1], names[2])
    else:
        ans = "{0}, {1} and {2} others like this".format(names[0], names[1], len(names) - 2)
    return ans
