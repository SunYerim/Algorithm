'''logic
    1. 입력 받고
    2. sorted, lambda 함수 사용해서 정렬
    근데 테케 통과까지 너무 오래 걸려서 비효율적인 코드인듯....'''
N = int(input())

students = []

for i in range(N):
    students.append(input().split())

# 국어 점수가 감소하는 순서로 => 영어 점수가 증가하는 순서 => 수학 점수가 감소 => 이름이 사전 순으로 증가하는 순서로.
sorted_students = sorted(students, key = lambda x : (-int(x[1]), int(x[2]), -int(x[3]), x[0]))

for student in sorted_students:
    print(student[0])