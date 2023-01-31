m, n = map(int, input().split())
hoho = []

for j in range(m, n+1):
    if j == 1:
        continue
    for i in range(2, int(j**0.5) + 1):
        if (j%i == 0):
            break
    else:
        print(j)

