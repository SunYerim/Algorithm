def solution(n):
    sum = 0
    num = 1
    while (num <= len(str(n))):
        sum += ((n%(10**num)) // (10**(num-1)))
        num += 1
    return sum