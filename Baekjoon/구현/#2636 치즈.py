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
                    
                

'''logic
1. n, m 입력받고 치즈의 상태를 입력받아 cheese에 저장
2. 총 걸리는 시간 저장할 count, 마지막으로 없어진 치즈의 수 저장할 last_cheese 0으로 초기화 시켜둠
3. queue에 cheese의 시작점인 [0,0]을 넣은채로 반복문을 시작함. 이때 한 타임 동안 없어지는 치즈 개수를 저장할 temp를
    0으로 초기화 시켜둠.
4. queue의 첫번째 값 꺼내 head에 저장하고 '상하좌우' 순으로 주변 탐색함.
 1) 주변이 0이라면 (회색) queue에 추가하고 해당 위치는 -1로 바꿈.
 2) 주변이 1이라면 없어질 치즈이므로(c 표기) temp를 1 증가시키고 해당위치는 -1로 바꿈.
5. queue가 비어서 안쪽 while문이 끝나면 temp의 수를 확인하여 이번 타임에 없어진 치즈가 0개일때, 반복문 종료한 뒤
    count와 last_cheese를 출력함.
6. temp가 0이 아니라면, cheese를 모두 돌며 -1로 바꿨던 값들을 0으로 바꿔줌.
7. 값을 모두 바꾼 뒤 없어진 치즈의 수인 temp의 값을 last_cheese에 저장하고 한 타임이 지났으므로 count 1 증가시킴.'''    