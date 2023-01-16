'''logic
    -연구소랑 비슷한 로직같아보임.
    1. '''

n = int(input())

data = [] # 입력 받아놓을
teacher = [] # 선생님의 위치 입력 받을 리스트.
wall = []
result = "NO"

# 방향 리스트
dx = [1,-1,0,0]
dy = [0,0,-1,1]

for i in range(n):
    data.append(list(map(str, input().split())))
    for j in range(n):
        if data[i][j] == 'T':
            teacher.append((i,j))

def check_t():
    global teacher, data
    for t in teacher:
        for i in range(4):
            x, y = t
            while 0<= x < n and 0<= y < n:
                if data[x][y] == 'O': # 장애물
                    break
                elif data[x][y] == 'S': # 학생 존재
                    return False
                x += dx[i]
                y += dy[i]
    return True

def dfs(count):
    global teacher, data, result, wall
    if count > 3:
        return
    if count == 3: # 장애물 3개 설치
        if check_t() is True:
            result = "YES"
            return
        else:
            result = "NO"
    
    if count < 3:
        for i in range(n):
            for j in range(n):
                if data[i][j] == 'X':
                    data[i][j] = 'O'
                    wall.append((i,j))
                    dfs(count+1)
                    if result == "YES":
                        return
                    wall.remove((i,j))
                    data[i][j] = 'X'

dfs(0)
print(result)