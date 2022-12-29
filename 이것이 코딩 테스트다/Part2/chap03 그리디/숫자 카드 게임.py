'''가장 숫자가 낮은 카드 선택 ==> min() 활용
    list에 반복문 돌며 추가하여 그 중에 max인 값의 index+1 반환'''

# N, M 입력 받음
N, M = map(int, input().split())

#입력받음 & min 값 넣는 리스트 생성
min_list = []
for i in range(N):
    num_list = list(map(int, input().split()))
    min_data = min(num_list)
    min_list.append(min_data)

#min_list 중에서 max값 반환해주면 됨.
print(max(min_list))