'''logic
    1. N을 입력받는다.
    2. 리스트에 N개의 수만큼 숫자를 입력받고 sort해준다.
    3. binary search 
    
    + 이진탐색 진행시 해당 숫자는 제외하고 탐색을 진행해줘야된다. 포함했더니 오류봉착
    + 그리고 음수도 들어올 수 있음.
    + target 값 제외하고 리스트 
    ...'''
# good number 위치한 index와 값
def search(index, target):
    new = num_list[:index] + num_list[index+1:]

    start = 0
    end = N - 2 # 마지막 인덱스에서 target값 하나 더 뺐으므로 N-2임

    while (start < end):
        sum = new[start] + new[end]
        if target < sum:
            end -= 1
        elif target > sum:
            start += 1
        else:
            return True
    return False

N = int(input())

num_list = list(map(int, input().split()))
num_list.sort()

count = 0
for i in range(len(num_list)):
    if (search(i, num_list[i])):
        count += 1
print(count)
