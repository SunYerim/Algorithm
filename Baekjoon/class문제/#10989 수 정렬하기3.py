n = int(input())
num = []
for i in range(n):
    x = int(input())
    num.append(x)


num.sort()

for i in range(n):
    print(num[i])