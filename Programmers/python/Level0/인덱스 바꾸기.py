def solution(my_string, num1, num2):
    answer = ''
    num = 0
    while (num < len(my_string)):
        if (num != num1 and num != num2):
            answer += my_string[num]
        elif (num == num1):
            answer += my_string[num2]
        elif (num == num2):
            answer += my_string[num1]
        
        num += 1
    return answer