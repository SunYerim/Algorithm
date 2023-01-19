'''logic
    1. N, M 입력받음
    2. list에 기타 강의 길이 입력 받음. N개
    3. 강의 순서 바뀌면 안 된다 했으므로 정렬은 따로 하면 안 됨.
    4. 이진 탐색 => M = 1일때 블루레이 크기의 최소는 sum(list)_강의 길이의 총합 (블루레이 길이 중 최대)
                => M = N일때 블루레이 크기의 최소는 max(list)_강의 길이가 가장 긴 것 (블루레이 길이 중 최소)
        두 개 값을 start, end 값으로 잡아 이분탐색 실행
'''

N, M = map(int, input().split())
lecture = list(map(int, input().split()))

# start end 초기값 지정
start, end = max(lecture), sum(lecture)

while (start<=end):
    mid = (start + end) // 2
    count = 0
    temp = 0
    for i in range(N):
        if (temp + lecture[i] > mid):
            count += 1
            temp = 0
        temp += lecture[i]

    if temp:
        count += 1
    else:
        count = 0
    

    if count <= M:
        end = mid-1
    else:
        start = mid + 1

print(start)