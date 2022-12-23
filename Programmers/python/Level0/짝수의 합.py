def solution(n):
    sum = 0
    num = []
    for i in range(0, n+1, 2):
        num.append(i)
    
    for j in range(0, len(num)):
        sum += num[j]
        
    return sum