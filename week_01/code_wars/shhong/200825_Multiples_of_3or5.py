def solution(number):
    total = sum(num * 3 for num in range(1, number//3 + 1) if (num * 3) < number)
    total += sum(num * 5 for num in range(1, number//5 + 1) if (num * 5) < number)
    total -= sum(num * 15 for num in range(1, number//15 + 1) if (num * 15) < number)
    return total
