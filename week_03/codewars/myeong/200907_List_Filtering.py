import re

def filter_list(l):
    relist=[]
    for filtering in l:
        if(isinstance(filtering,int)):
            relist.append(filtering)
    return relist