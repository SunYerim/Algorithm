def solution(n):
    answer = 0
    num = 1
    while (n >= num * num):
        if (n == num * num):
            answer = 1
            break
        else:
            answer = 2
        num += 1

    return answer