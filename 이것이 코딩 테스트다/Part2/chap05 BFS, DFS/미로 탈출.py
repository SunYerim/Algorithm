'''logic
    1. 간선의 비용이 동일하고 최단거리를 찾는 문제다 ? ===> BFS 사용
    '''
from collections import deque

N, M = map(int, input().split())

graph = []
for i in range(N):
    graph.append(list(map(int, input())))

# 4방향 정의 (상하좌우)
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
    queue = deque()
    queue.append((x, y))
    # 큐가 빌 때까지 반복.
    while queue:
        x, y = queue.popleft()
        # 현 위치로부터 4방향으로 확인함.
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 미로 공간 벗어난 경우 무시함.
            if nx < 0 or ny < 0 or nx >= N or ny >= M:
                continue
            # 벽인 경우에도 무시한다.
            if graph[nx][ny] == 0:
                continue
            # 해당 노드 처음 방문하는 경우 최단 거리 기록
            if graph[nx][ny] == 1:
                graph[nx][ny] = graph[x][y] + 1
                queue.append((nx, ny))

    return graph[N-1][M-1]

print(bfs(0, 0))