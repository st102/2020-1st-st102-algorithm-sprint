def digital_root(n):
    number = str(n)
    while len(number) != 1:
        number = str(sum(int(num) for num in number))
    return int(number)



def solution(str1, str2):
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    s1 = [str1[i:i+2].lower() for i in range(len(str1) - 1)]
    s2 = [str2[i:i+2].lower() for i in range(len(str2) - 1)]
    for s1item in list(s1):
        if s1item[0] not in alphabet or s1item[1] not in alphabet:
            s1.remove(s1item)
    for s2item in list(s2):
        if s2item[0] not in alphabet or s2item[1] not in alphabet:
            s2.remove(s2item)

    intersec = sum(s1.count(item) if s1.count(item) < s2.count(item) else s2.count(item) for item in list(set(s1) & set(s2)))
    union   = sum(s1.count(item) if s1.count(item) >= s2.count(item) else s2.count(item) for item in list(set(s1) | set(s2)))

    answer = 1 if union == 0 else intersec/union
    return int(answer * 65536)