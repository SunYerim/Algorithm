arr1 = [] # 전체 행렬
max_num = []
max_place = []

for row in range(9):
    row = list(map(int, input().split()))
    max_num.append(max(row))
    arr1.append(row)

print(max(max_num))
print(max_num.index(max(max_num))+1, arr1[max_num.index(max(max_num))].index(max(max_num))+1, end = ' ' )
