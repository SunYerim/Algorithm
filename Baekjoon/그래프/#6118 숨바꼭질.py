'''logic
    1. bfs로 푸는 것 같음.
    2. 1번 헛간부터 탐색하며 방문 거리 체크
	3. 체크한 방문 거리 토대로 출력값 예시 수행'''
from collections import deque

# bfs 탐색
def bfs(v):
    queue = deque([v])
    
    visited[v] = 1

    while queue:
        target = queue.popleft()
        # 연결된 헛간을 확인.
        for i in graph[target]:
            # 방문하지 않은 헛간이라면 방문한다.
            if visited[i] == 0:
                # 방문 거리를 체크
                visited[i] = visited[target] + 1
                queue.append(i)

# n, m 입력받음
n, m = map(int, input().split())

# 노드 방문 여부와 순서 확인
visited = [0 for i in range(n+1)]

# 각 연결된 노드를 표현
graph = [[] for _ in range(n+1)]

# 각 그래프 연결 관계
for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

# 1번 헛간부터 탐색 시작!
bfs(1)

# 최대 값의 인덱스 값 출력, 첫번째 헛간을 1로 두었기 때문에 최대값에서 1을 빼준 값을 출력, 최대 값의 개수 출력
print(visited.index(max(visited)), max(visited) - 1, visited.count(max(visited)))