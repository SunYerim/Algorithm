def solution(numbers):
    # 배열 내의 숫자들 끼리만 비교해야 하기 때문에 배열의 가장 첫 곱셈으로 초기화 해주어야 함.
    answer = numbers[0] * numbers[1]
    for i in range(len(numbers)):
        for j in range(i+1, len(numbers)):
            if (numbers[i] * numbers[j] > answer):
                answer = numbers[i] * numbers[j]
            
    return answer