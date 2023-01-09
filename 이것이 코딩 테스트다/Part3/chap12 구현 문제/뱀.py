n = int(input())
k = int(input())

map = [[0] * (n+1) for _ in range(n+1)]
direction = []

# 사과 입력 받고 그 곳은 따로 표시를 해둬야함. (1로)
for _ in range(k):
    x, y = map(int, input().split())
    map[x][y] == 1

# 방향 회전 정보 입력
num = int(input())
for _ in range(num):
    x, c = input().split()
    direction.append((int(x), c))

# 뱀 움직이므로 동서남북 방향 표시
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

# D와 L 나올 때 이동 생각..
# 아ㅏㅏ 할 수 있을 거 같은데 음 하 스터디 후 해결!