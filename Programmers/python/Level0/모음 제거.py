def solution(my_string):
    answer = ''
    moeum = ['a','e','i','o','u']
    for i in range(len(my_string)):
        if (my_string[i] not in moeum):
            answer += my_string[i]
    return answer