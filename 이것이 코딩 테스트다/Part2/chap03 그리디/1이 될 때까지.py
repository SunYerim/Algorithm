'''while문으로 N >= 1일때까지만 수행하는 조건 세우고 아래 조건에 따라 코딩'''
# N, K 입력받기
N, K = map(int, input().split())

# 조건에 따라 연산 되게끔
# count 값 설정
count = 0
while(N > 1):
    if (N % K != 0):
        N -= 1
        count += 1
    else:
        N  = N // K
        count += 1

print(count)