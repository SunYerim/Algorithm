'''logic
    1. chess판 입력 받고 방향 좌표 저장
    2. 출발점부터 n번만큼 bfs 돌림'''

from collections import deque
import sys
input = sys.stdin.readline

n = int(input().rstrip())

def bfs():
    dx = [-1, 1, 2, 2, 1, -1, -2, -2]
    dy = [2, 2, 1, -1, -2, -2, -1, 1]

    q = deque()
    q.append((startX, startY))

    while q:
        x, y = q.popleft()
        if x == endX and y == endY:
            return chess[x][y] - 1
        # 이동 방향이 8방향이므로 반복문 8번 반복
        for i in range(8):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0<=nx<l and 0<=ny<l and chess[nx][ny] == 0:
                chess[nx][ny] = chess[x][y] + 1
                q.append((nx, ny))

for _ in range(n):
    l = int(input().rstrip())
    startX, startY = map(int, input().rstrip().split())
    endX, endY = map(int, input().rstrip().split())
    chess = [[0]*l for _ in range(l)] 
    # 출발지는 방문한 것으로 체크+1
    chess[startX][startY] = 1
    
    print(bfs())
