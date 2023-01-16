'''logic
    1. list append 후 sort 시킴
    2. 원소 개수가 홀수일 때 => 중앙, 짝수일 때 => 반으로 나눈 몫 위치'''
N = int(input())
count = 1e9
sum = 0

house = list(map(int, input().split()))

house.sort()

if (len(house) % 2 == 0):
    print(house[N//2-1])
else:
    print(house[N//2])