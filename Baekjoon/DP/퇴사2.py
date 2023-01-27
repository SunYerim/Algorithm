'''logic
    1. 편의상 0일차도 포함하였습니다.
    2. '''

n = int(input())
t, p = [0 for _ in range(n+1)], [0 for _ in range(n+1)]

for i in range(1, n+1):
    t[i], p[i] = map(int, input().split())

dp = [0 for _ in range(n+1)]


for i in range(1, n+1):
    