import sys
import heapq
INF = int(1e9)

n, m, x = map(int, sys.stdin.readline().split())

list1 = [[] for _ in range(n+1)]

for i in range(m):
    a,b, c = map(int, sys.stdin.readline().split())
    list1[a].append((b, c))

def dijkstra(start):
    # heap 생성
    q = []
    # heap에 원소 추가
    heapq.heappush(q, (0, start))
    distance[start] = 0
    while q:
        dist, now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in list1[now]:
            cost = dist + i[1]
            if cost < distance[i[0]]:
                distance[i[0]] = cost
                heapq.heappush(q, (cost, i[0]))
    return distance

result = [[]]
time_list = []

'''n번만큼 for문 돌면서 다익스트라 함수 실행 => 거리 배열은 매 반복문 실행시마다 초기화 시켜줘야됨.
    ==> 그렇게 하지 않으면 최초 실행으로 인해 바뀐 distance를 기준으로 다시 한 번 함수를 실행하기 때문에 정확한 distance 측정 불가'''

for i in range(1,n+1):
    distance = [INF] * (n+1)
    result.append(dijkstra(i))
for i in range(1, n+1):
    time_list.append(result[i][x] + result[x][i])

print(max(time_list))
