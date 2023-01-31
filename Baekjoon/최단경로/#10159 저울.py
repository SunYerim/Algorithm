'''logic
    1. 키 순서랑 비슷한 거 같아용'''

INF = int(1e9) #무한을 의미하는 값
n = int(input())
m = int(input())

graph = [[INF]*n for _ in range(n)]

for _ in range (m):
    a, b = map(int, input().split())
    graph[a-1][b-1] = 1

# 플로이드-와샬 알고리즘
for k in range(n):
    for i in range(n):
        for j in range(n):
            if graph[i][k] == 1 and graph[k][j] == 1:
                graph[i][j] = 1


for i in range(n):
    count = 0
    for j in range(n):
        # i와 j 간의 값이 1이 아니면 무게 비교할 수 없으므로 count를 증가시킴.
        if (graph[i][j] != 1 and graph[j][i] != 1):
            count += 1
    # 자기 자신을 비교한 경우를 제외하기 위해 count -1을 출력
    print(count-1)