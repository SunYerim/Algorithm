'''logic
    1. 바이러스가 존재하는 부분들 (0이 아닌 것)에 대한 좌표를 virus 리스트에 따로 저장.
    2. virus 리스트에 있는 좌표값에 대해서만 bfs를 수행하면 됨.
    3. 해당 지역의 좌표가 0인 경우에만 탐색 가능하다.
    -----------------------------------------
    - virus.append(((graph[i][j], i, j))) 처럼 저장 한 이유 => 입력을 다 한 후 virus.sort()를 하게 되면
      맨 앞 원소를 기준으로 오름차순 정렬을 하기 때문에 별도의 처리 없이 오름차순 된 virus 리스트 그대로 bfs를 수행하면
      숫자가 낮은 바이러스부터 우선적으로 탐색 가능
    '''
from collections import deque

n, k = map(int, input().split())

graph = []
virus = []

for i in range(n):
    graph.append(list(map(int ,input().split())))
    for j in range(n):
        if graph[i][j] != 0:
            virus.append(((graph[i][j], i, j)))

s, x, y = map(int, input().split())

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(s, X, Y):
    q = deque(virus)
    count = 0
    while q:
        if count == s:
            break
        for _ in range(len(q)):
            prev, x, y = q.popleft()
            for i in range(4):
                xx = x + dx[i]
                yy = y + dy[i]
                if (0 <= xx < n and 0 <= yy < n):
                    if graph[xx][yy] == 0:
                        graph[xx][yy] = graph[x][y]
                        q.append((graph[xx][yy], xx, yy))
        count += 1
    return graph[X-1][Y-1]

virus.sort()
print(bfs(s, x, y))
