N = int(input())

graph = []

for _ in range(N):
    num = int(input())
    graph.append(num)


graph.sort(key = lambda x: x)

for i in range(N):
    print(graph[i])