from itertools import permutations

def solution(babbling):
    ong = ["aya", "ye", "woo", "ma"]
    johab = []
    answer = 0
    for i in range(1, len(ong)+1):
        for j in permutations(ong, i):
            johab.append(''.join(j))
            
    for i in babbling:
        if i in johab:
            answer += 1
            
    return answer

