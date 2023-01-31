'''logic
    1. stack 자료구조를 사용해보자.
    2. 0 나올때 아닐때 구분해서 계산 고고'''

k = int(input())
num_list = []
for i in range(k):
    num = int(input())
    if (num != 0):
        num_list.append(num)
    else:
        num_list.pop(-1)

print(sum(num_list))