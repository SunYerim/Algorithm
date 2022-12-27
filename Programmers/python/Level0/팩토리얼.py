def solution(n):
    answer = 0
    num = 1
    factorial_arr = []
    for i in range(1, 11):
        num *= i
        factorial_arr.append(num)
        
    for i in range(len(factorial_arr)):
        if (n == factorial_arr[i]):
            answer = i+1
        elif (n > factorial_arr[i] and n < factorial_arr[i+1]):
            answer = i+1
    return answer
