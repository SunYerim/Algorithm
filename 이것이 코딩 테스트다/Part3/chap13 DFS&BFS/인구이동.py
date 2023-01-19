'''logic
    1. bfs로 문제 해결 => queue
    2. 이중 for문 사용해 각 위치마다 bfs 실행
    3. 방문한 적 있거나, check 함수 통해 bfs 실행할지말지 결정.
    4. 인구이동 일어나는 한 계속 반복해야 하므로 population_flag 변수 사용해 인구변화 유무 표시함.
    '''
import sys
from collections import deque

N, L, R = map(int, input().split())
country = []

# 방향 탐색 
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

population_flag = True
result = 0

for _ in range(N):
    country.append([int(x) for x in sys.stdin.readline().rstrip().split()])

''' 연합한 나라들을 담을 리스트 union_list와 연합 인구수 union_person 변수 설정함.
    4방면으로 L과 R 조건 확인하며 bfs 탐색
    큐에 append 할 때마다 union_list와 union_person을 업데이트 해줌.'''
def bfs(x,y):
    global population_flag
    union_list = []
    union_person = 0
    deq = deque()

    visited[x][y] = True
    union_list.append([x,y])
    union_person += country[x][y]
    deq.append([x,y])

    while deq:
        a,b = deq.popleft()
        for i in range(4):
            nx, ny = a + dx[i], b + dy[i]
            if 0 <= nx < N and 0 <= ny < N and not visited[nx][ny]:
                if L <= abs(country[a][b] - country[nx][ny]) <= R:
                    visited[nx][ny] = True
                    deq.append([nx,ny])
                    union_list.append([nx,ny])
                    union_person += country[nx][ny]

    union_len = len(union_list)

    if union_len >= 2:
        for u in union_list:
            country[u[0]][u[1]] = union_person // union_len
        population_flag = True

'''연합국가가 1개라면 bfs함수를 호출할 필요가 없음 ==> 
    미리 주변 국가와 인구수 차이를 판단해 리턴을 해준다.(1, 0)'''

def check(x, y):
    for i in range(4):
        nx, ny = x + dx[i], y + dy[i]
        if 0 <= nx < N and 0 <= ny < N:
            if L <= abs(country[x][y] - country[nx][ny]) <= R:
                return 1
    return 0

while population_flag:
    population_flag = False
    visited = [[False] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if not visited[i][j] and check(i,j):
                bfs(i,j)

    if population_flag:
        result += 1

print(result)