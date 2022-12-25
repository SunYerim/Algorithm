import re

def solution(my_string):
    answer = 0
    numbers = re.sub(r'[^0-9]','', my_string)
    for i in range(len(numbers)):
        answer += int(numbers[i])
    return answer