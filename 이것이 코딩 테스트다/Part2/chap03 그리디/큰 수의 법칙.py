'''list 입력받아서 sort()  => 큰 수, 작은 수 저장 후 문제 조건에 맞춰 연산값 반환하도록 함.'''
# N, M, K 입력받기
N, M, K = map(int, input().split())

#N개의 자연수 입력 -> list
num_list = list(map(int, input().split()))

#오름차순 정렬
num_list.sort()

#1등, 2등 수 저장
one = num_list[-1]
two = num_list[-2]

# one 더해야 하는 횟수 count
one_count = (M // K) * K
two_count = M % K

# 연산 
count = 0
for i in range(one_count):
    count += one
for i in range(two_count):
    count += two

print(count)