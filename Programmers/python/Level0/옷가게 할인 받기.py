def solution(price):
    if (price < 300000 and price >= 100000):
        answer = (price * 0.95)//1
    elif (price < 500000 and price >= 300000):
        answer = (price * 0.9)//1
    elif (price >= 500000):
        answer = (price * 0.8)//1
    else:
        answer = price
    return answer