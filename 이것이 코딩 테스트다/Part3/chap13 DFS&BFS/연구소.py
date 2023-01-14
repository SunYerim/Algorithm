'''logic
    1. 벽 세우기
    2. 바이러스 감염 => dfs
    3. 안전 영역 구하기'''

n, m = map(int, input().split())
# 초기맵
initial = [list(map(int, input().split())) for _ in range(m)] 
#벽을 설치한 뒤
final = []

# 방향에 대한 리스트
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

# 바이러스 전파 함수
def virus(x, y):
    for i in range(4):
        xx = x + dx[i]
        yy = y + dy[i]
        if (0<=xx<n and 0<=yy<m and final[xx][yy] == 0):
            final[xx][yy] = 2
            virus(xx, yy)

# 안전 영역 개수 구하기
def safe():
    count = 0
    for i in range(n):
        for j in range(m):
            if final[i][j] == 0:
                count += 1
    return count

def DFS(count):
    global result
    if count == 3:
        for i in range(n):
            for j in range(m):
                final[i][j] = initial[i][j]
                # tmp[i].append(lab[i][j])

        for i in range(n):
            for j in range(m):
                if final[i][j]==2:
                    virus(i,j)
        result = max(result, safe())
        return
    else:
        for i in range(n):
            for j in range(m):
                if initial[i][j] == 0:
                    initial[i][j]=1
                    count+=1
                    DFS(count)
                    initial[i][j]=0
                    count-=1
result=0
DFS(0)
print(result)