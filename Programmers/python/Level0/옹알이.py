def solution(babbling):
    ong = ["aya", "ye", "woo", "ma"]
    answer = 0;
    for i in range (0, len(babbling)):
        if babbling[i] in ong:
            answer = answer + 1
    return answer


babbling = ["aya" "yee", "u", "maa", "wyeoo"]
print(solution(babbling))

