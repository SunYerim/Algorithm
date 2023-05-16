N, M = map(int, input().split())

rice = list(map(int, input().split()))
rice.sort()

# 시작점과 끝점 설정
start = 0
end = rice[-1]

# 정답 변수
result = 0

# 이진 탐색으로
while (start <= end):
    total = 0
    mid = (start + end) // 2
    for x in rice:
        # 잘랐을때 떡의 양 계산
        if (x > mid):
            total += x - mid
       
    if (total < M):
        end = mid - 1
    else:
        result = mid
        start = mid + 1

print(result)