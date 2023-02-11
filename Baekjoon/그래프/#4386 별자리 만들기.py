'''logic
    1. kruskal 알고리즘 사용
    2. '''

import sys
import math


num = int(sys.stdin.readline())
# 별의 좌표 저장
stars = []
# 가중치 저장 (경로 비용)
route = []

for _ in range(num):
    x, y = map(float, sys.stdin.readline().split())
    stars.append((x, y))

# 별 간의 거리 계산 (가중치)
for i in range(num-1):
    for j in range(i, num):
        distance = round(math.sqrt((stars[i][0] - stars[j][0]) ** 2 + (stars[i][1] - stars[j][1]) ** 2), 2)
        # 자기 자신으로 가는 거리는 계산 안 함
        if i == j:
            continue
        route.append((distance, i, j))
        route.append((distance, j, i))

route.sort(key = lambda x: x[0])
parent = list(range(num+1))

# union-find
def union(a, b):
    a = find(a)
    b = find(b)

    if a > b:
        parent[a] = b
    else:
        parent[b] = a

def find(a):
    if a == parent[a]:
        return a
    parent[a] = find(parent[a])
    return parent[a]

result = 0

for cost, a, b in route:
    if (find(a) != find(b)):
        union(a, b)
        result += cost

print(result)

