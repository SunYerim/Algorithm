def solution(numbers):
    answer = 1
    new_arr  = []
    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            new_arr.append(numbers[i] * numbers[j])
    new_arr.sort()
    return new_arr[-1]