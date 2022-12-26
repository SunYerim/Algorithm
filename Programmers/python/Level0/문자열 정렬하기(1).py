def solution(my_string):
    answer = []
    numbers = ['0','1','2','3','4','5','6','7','8','9']
    for i in range(len(my_string)):
        if my_string[i] in numbers:
            answer.append(int(my_string[i]))
    
    answer.sort()
    return answer