# 가로세로 입력받기
n, m = map(int, input().split())
cheese = [list(map(int, input().split())) for _ in range(n)]

# 좌우상하 탐색위한 좌표
dx = [0, 0, 1, -1]
dy = [-1, 1, 0, 0]

# 출력값 2개
count = 0
last_cheese = 0

while True:
    queue = [[0, 0]]
    # 마지막 turn에 남아있는 chesse 개수 출력 위한 temp 변수
    temp = 0
    while queue:
        head = queue.pop(0)
        for i in range(4):
            x = head[0] + dx[i]
            y = head[1] + dy[i]
            if (x>-1 and x<n and y>-1 and y<m):
                if cheese[x][y] == 0:
                    cheese[x][y] = -1
                    queue.append([x, y])
                if cheese[x][y] == 1:
                    cheese[x][y] = -1
                    temp += 1
    if temp == 0:
        break
    for i in range(n):
        for j in range(m):
            if cheese[i][j] == -1:
                cheese[i][j] = 0
    last_cheese = temp
    count += 1
    
print(count)
print(last_cheese)
                    
                
    