'''logic
    1. DFS
    2. 그리고 강강수월레 처럼 마지막과 처음이 연결? 되어있어야 한다.즉, 사이클 있어야 됨.'''
import sys
sys.setrecursionlimit(10**6) # 재귀 에러 방지 위함

t = int(sys.stdin.readline())

# dfs 함수
def dfs(x):
    global result
    visited[x] = True
    # 사이클을 이루는지 확인하기 위함
    cycle.append(x)
    number = numbers[x]

    if visited[number]:
        # 사이클이 가능한지 여부
        if number in cycle:
            result += cycle[cycle.index(number):] #사이클 되는 구간 부터만 한 팀을 이룬다.
        return
    else:
        dfs(number)

for _ in range(t):
    n = int(sys.stdin.readline())
    numbers = [0] + list(map(int, sys.stdin.readline().split()))
    visited = [True] + [False] * n # 방문 여부 
    result = []

    for i in range(1, n+1):
        if not visited[i]: # 방문 안 했으면
            cycle = []
            dfs(i) # dfs 돌려
    
    # team에 없는 사람 수 => 전체에서 result의 길이만큼 뺀다.
    
    print(n - len(result))