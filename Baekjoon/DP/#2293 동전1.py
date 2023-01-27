'''logic
    "점화식"
    1. dp테이블
    2. n원을 만들 수 있는 경우의 수는 이전 행의 n원을 만들 수 있는 경우의 수와
       n원에서 현재 동전의 가치 k원을 뺀 가치의 경우의 수의 합으로 이루어짐.
    ==> dp[n] = dp[n] + dp[n-k] (if n-k >= 0)'''

n, k = map(int, input().split())
coin = list(int(input()) for i in range(n))

dp = [0 for _ in range(k+1)]
dp[0] = 1

for i in coin:
    for j in range(i, k+1):
        if (j-i) >= 0:
            dp[j] += dp[j-i]

print(dp[k])