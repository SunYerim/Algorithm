m = int(input())

num_list = list(map(int, input().split()))
count = 0
num_list.sort() # 오름차순 정렬

'''공포도가 X인 모험가는 반드시 X명 이상'''
max_num =  max(num_list)
num1 = num_list[0]

#max number이 바뀌거나 max number만큼 돌았을 경우 total++
for i in range(m):
    # max값이 바뀌는 경우 total++
    if (num_list[i] > num1):
        count += 1
        num1 = num_list[i]
    # max number만큼 돌았을 경우
    elif ((num1 == max_num) and (i - num_list.index(max_num) == max_num - 1)):
        count += 1
    
print(count)