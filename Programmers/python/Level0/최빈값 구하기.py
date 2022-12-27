def solution(array):
    times_list = [[0, i] for i in range(max(array) + 1)]
    for num in array:
        times_list[num][0] += 1
    times_list.sort(reverse = True)
    return times_list[0][1] if times_list[0][0] != times_list[1][0] else -1