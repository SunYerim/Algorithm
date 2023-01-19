'''logic
    1. 필요한 내용 모두 입력받은 후
    2. 재귀로 이진탐색 실행'''

def binary_search(array, target, start, end):
    # 아예 조건 성립이 안 되는 경우 배제
    while start <= end:
        mid = (start + end) // 2
        # 찾고자 하는 target이 중간값인 경우
        if (array[mid] == target):
            return mid
        # 찾고자하는 target이 중간값의 값보다 작은 경우
        elif (array[mid] > target):
            end = mid - 1
        # 찾고자하는 target이 중간값의 값보다 큰 경우
        else:
            start = mid + 1
    return None
    
N = int(input())
market_array = list(map(int, input().split()))
market_array.sort() # 이진 탐색 위해 정렬

M = int(input())
consumer_array = list(map(int, input().split()))

for i in consumer_array:
    # 해당 부품 존재하는지 binary search 통해 확인
    result = binary_search(market_array, i, 0, N-1)
    if (result != None):
        print('yes', end = ' ')
    else:
        print('no', end = ' ')



