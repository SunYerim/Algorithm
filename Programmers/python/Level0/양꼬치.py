def solution(n, k):
    sum = n * 12000 + k * 2000
    sum -= 2000 * (n//10)
    return sum