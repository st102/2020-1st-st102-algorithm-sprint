def likes(names):
    how_many = len(names)
    if how_many >= 4:
        return (
            "{}, {}".format(names[0], names[1])
            + " and "
            + "{} others like this".format(how_many - 2)
        )
    elif how_many == 3:
        return "{}, {} and {} like this".format(names[0], names[1], names[2])
    elif how_many == 2:
        return "{} and {} like this".format(names[0], names[1])
    return "{} likes this".format(names[0]) if how_many  else "no one likes this"