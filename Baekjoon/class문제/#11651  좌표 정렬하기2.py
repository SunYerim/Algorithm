N = int(input())
num_list = []
for _ in range(N):
    x, y = map(int, input().split())
    num_list.append([y, x])

arr1 = sorted(num_list)

for y, x in arr1:
    print(x, y)