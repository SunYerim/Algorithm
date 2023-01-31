'''logic
    1. 입력받고,
    2. 4방향 거리 list 저장후
    3. 제일 작은 값 print'''

x, y, w, h = map(int, input().split())

print(min(y, x, w-x, h-y))