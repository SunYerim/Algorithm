num = int(input())
arr1 = list(map(int, input().split()))

n = int(input())
arr2 = list(map(int, input().split()))

for num in arr2:
    print(1) if num in arr1 else print(0)


# 이분 탐색 이용해서
number = int(input())
arr1 = list(map(int, input().split()))
arr1.sort()

n = int(input())
arr2 = list(map(int, input().split()))

# arr2의 각 원소별로 이분탐색 진행
for num in arr2:
    left ,right = 0, number - 1
    isExist = False

    # 이분탐색
    while left <= right:
        mid = (left + right) // 2
        if num == arr1[mid]:
            isExist = True
            print(1)
            break
        elif num > arr1[mid]:
            left = mid + 1
        else:
            right = mid -1
    
    if not isExist:
        print(0)