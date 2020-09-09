def filter_list(l):
    list_of_return = []
    for check_integer in l :
        if isinstance(check_integer , int):
            list_of_return.append(check_integer)
    
    return list_of_return