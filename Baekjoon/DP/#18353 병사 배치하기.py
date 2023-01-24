'''logic
    => 'LIS(Longest Increasing Subsequence): 가장 긴 증가하는 부분 수열' 개념
        -하나의 수열이 주어졌을 때, 값들이 증가하는 형태의 가장 긴 부분 수열을 찾는 문제.
    1. 이번 문제는 전투력이 높은 병사가 앞쪽에 오도록 '내림차순 배치'
    2. '가장 긴 감소하는 부분 수열'길이 찾는 문제
    3. '''

N = int(input())

soldier = list(map(int, input().split()))
soldier.reverse()

# 다이나믹 프로그래밍 위한 DP 테이블 초기화
dp = [1] * N

# LIS 알고리즘 시행
for i in range(1, N):
    for j in range(0, i):
        if (soldier[j] < soldier[i]):
            dp[i] = max(dp[i], dp[j] + 1)

# 열외 시켜야하는 병사
print(N - max(dp))