bingo = []
success = []

for i in range(5):    
	bingo.append(list(map(int, input().split())))

for j in range(5):
    success.append(list(map(int, input().split())))

for i in range(5):
    print(bingo[i])

print("---------------------")

for i in range(5):
    print(success[i])
