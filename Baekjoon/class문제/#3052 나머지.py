
trash_list = []
for i in range(10):
    num = int(input())

    trash_list.append(num%42)

print(len(list(set(trash_list))))