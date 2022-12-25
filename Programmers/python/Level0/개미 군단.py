def solution(hp):
    answer = 0
    num1 = hp // 5
    num2 = (hp % 5) // 3
    num3 = (hp % 5) % 3
    answer = num1 + num2 + num3
    return answer