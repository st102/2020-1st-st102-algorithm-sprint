def solution():

    def get_no_self_number(element):
        string_element = str(element)
        no_self_number = element
        for number in range(len(string_element)):
            no_self_number += int(string_element[number])
        return no_self_number

    no_self_number_set = set()

    for index in range(1, 10000 + 1):
        if index not in no_self_number_set:
            print(index)

        no_self_number_set.add(get_no_self_number(index))


if __name__ == '__main__':
    solution()

