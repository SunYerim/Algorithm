def solution(score):
    answer = []
    average_score = []
    for i in score:
        average_score.append(sum(i)/len(i))
    
    sort_arr = sorted(average_score, reverse = True)
    for i in average_score:
        answer.append(sort_arr.index(i)+1)
    
    
    return answer