def line_up():
    N = int(input())
    condition = list(map(int, input().split()))

    line = []

    for num in range(len(condition), 0, -1):
        line.insert(condition[num - 1], num)

    return ' '.join(map(str, line))


if __name__ == '__main__':
    print(line_up())
