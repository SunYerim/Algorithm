def solution(rsp):
    answer = ''
    win = {"2" : "0", "0" : "5", "5": "2"}
    for i in range(len(rsp)):
            if (rsp[i] in win):
                answer += win[rsp[i]]
    return answer