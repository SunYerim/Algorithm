N = int(input())
students = []
for i in range(N):
    students.append(input().split())
    
 # 나이 순서 오름차순으로
sorted_students = sorted(students, key = lambda x : int(x[0]))


for i in range(N):
    print(sorted_students[i][0], sorted_students[i][1])