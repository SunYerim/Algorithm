'''logic
    1. n, m 입력받고
    2. 도시정보들 리스트 입력 받아옴
    3. house와 chicken shop 좌표 저장할 빈 리스트 생성
    4. 치킨집 최대 M개 고르기 (1개 ~ M개) => "조합" 으로 구현해서 도시의 치킨거리가 가장 작은 조합 pick
    ---> 조합은 생각도 못 했다 DFS로 해결하려했음!'''

import sys
# 조합
from itertools import combinations

input = sys.stdin.readline

n, m = map(int, input().split())
answer = 999999

# house와 chicken shop 좌표 저장할 빈 리스트 생성
house, chicken = [], []

#반복문 돌리며 도시의 정보 받아오고 이때 1이나 2일경우 house와 chicken 리스트에 좌표 위치 저장시켜 놓는다.
for i in range(n):
    city = list(map(int, input().split()))
    for j in range(n):
        if city[j] == 1:
            house.append([i, j])
        elif city[j] == 2:
            chicken.append([i, j])

# 조합 구현(치킨집을 1개 고르는 조합부터 M개 고르는 조합까지 구한 후 각각 치킨 거리를 계산해 도시의 치킨 거리가 가장 작은 조합 선택)
for pick in combinations(chicken, m):
    total = 0
    for h in house:
        distance = 9999
        for j in range(m):
            distance = min(distance, abs(h[0] - pick[j][0]) + abs(h[1] - pick[j][1]))
        total += distance
    answer = min(answer, total)

print(answer)
