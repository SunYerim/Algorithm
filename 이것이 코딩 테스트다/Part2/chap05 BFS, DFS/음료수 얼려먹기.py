'''logic
    1. dfs 함수 구현
    2. 현 위치에서 상하좌우 살펴본 뒤 주변 지점 중 0이면서 아직 방문 이전인 곳이 있으면 방문.
    3. 방문 했으면 방문 처리 해줘야한다.
    4. 연결된 모든 지점 방문하면서 반복. '''

N, M = map(int, input().split())

graph = []
for i in range(N):
    graph.append(list(map(int, input())))

def dfs(x, y):
    # 주어진 범위 벗어나는 경우 즉시 종료
    if x <= -1 or x >= N or y <= -1 or y >= M:
        return False
    # 현재 노드를 방문하지 않았다면
    if graph[x][y] == 0:
        # 해당 노드 방문 처리
        graph[x][y] = 2
        # 상하좌우 탐색 고고
        dfs(x-1, y)
        dfs(x, y-1)
        dfs(x+1, y)
        dfs(x, y+1)
        return True
    return False

# 모든 위치에 음료수 채우기
count = 0
for i in range(N):
    for j in range(M):
        if (dfs(i, j) == True):
            count += 1

print(count)