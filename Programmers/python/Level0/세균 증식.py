def solution(n, t):
    num = 1
    while (num <= t):
        n *= 2
        num += 1
    answer = n
    return answer