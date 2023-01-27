a, b, c = map(int, input().split())
num_list = []
num_list.append(a)
num_list.append(b)
num_list.append(c)

num_list.sort()
money = 0

if (num_list[0]==num_list[1] and num_list[1]==num_list[2] and num_list[2]==num_list[0]):
    money = 10000 + (num_list[0] * 1000)
elif (num_list[0]!=num_list[1] and num_list[1]!=num_list[2] and num_list[2]!=num_list[0]):
    money = num_list[2] * 100
elif (num_list[0]==num_list[1] and num_list[1]!=num_list[2] and num_list[2] != num_list[0]):
    money = 1000 + (num_list[0] * 100)
elif (num_list[1]==num_list[2] and num_list[2]!=num_list[0] and num_list[0] !=num_list[1]):
    money = 1000 + (num_list[1] * 100)
elif (num_list[2]==num_list[0] and num_list[0]!=num_list[1] and num_list[1]!=num_list[2]):
    money = 1000 + (num_list[2] * 100)

print(money)
