from collections import deque

m, n = map(int,input().split(' '))
tomato = [list(map(int, input().split())) for _ in range(n)]

queue = deque([]) #좌표 입력받을 queue 생성
move1, move2 = [-1, 1, 0, 0], [0, 0, -1, 1]#좌우/하상
day = 0 #tomato 익히는데 걸리는 날짜

for i in range(n):
    for j in range(m):
        if tomato[i][j] == 1: #토마토 존재하는 좌표 queue 저장
            queue.append([i,j])

def tomato_bfs():
    while queue:
        x, y = queue.popleft() #토마토 존재 좌표 확인
        for i in range(4): #상하좌우 확인
            nx, ny = move1[i]+x, move2[i]+y
            if (0 <= nx < n) and (0 <= ny < m) and tomato[nx][ny] == 0:
                tomato[nx][ny] = tomato[x][y] +1
                queue.append([nx, ny]) #토마토 존재 +1

tomato_bfs()
for i in tomato:
    for j in i:
        if j == 0:
            print(-1)
            exit(0)
    day = max(day,max(i))

print(day-1)






            