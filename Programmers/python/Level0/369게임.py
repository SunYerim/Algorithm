def solution(order):
    answer = 0
    num_str = str(order)
    for i in range(len(num_str)):
        if (num_str[i] in ['3', '6', '9']):
            answer += 1
    return answer