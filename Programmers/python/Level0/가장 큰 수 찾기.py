def solution(array):
    num = 0
    num_index = 0
    answer = []
    for i in range(len(array)):
        if (array[i] > num):
            num = array[i]
            num_index = i
    answer.append(num)
    answer.append(num_index)
    return answer