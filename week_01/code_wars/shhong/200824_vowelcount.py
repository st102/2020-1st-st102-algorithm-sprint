"""def get_count(input_str):
    num_vowels = 0
    for s in input_str:
        if s in 'aeiou':
            num_vowels += 1
    return num_vowels

print(get_count(input()))"""

def getCount(s):
    return ((c in 'aeiou' for c in s))

print(getCount(input()))