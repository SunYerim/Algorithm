def solution(cipher, code):
    answer = ''
    num = 1
    while (code * num < len(cipher)+1):
        answer += cipher[(code * num)-1]
        num += 1
    return answer