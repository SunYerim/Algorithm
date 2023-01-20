'''logic
    1. N 입력받고, 용액 특성값을 나타내는 N개 정수 liquid list에 입력 받음.
    2. 양 끝점을 start, end로 잡음.
    3. sum => liquid의 start와 end가 가리키는 위치 값의 합
    4. sum 값에 따라, 동작 실행
    '''
N = int(input())

liquid = list(map(int, input().split(' ')))
liquid.sort()

start = 0
end = N-1

min = 10e9

while start < end:
    sum = liquid[start] + liquid[end]
    
    if abs(sum) < min:
        min = abs(sum)
        answer = liquid[start], liquid[end]
    
    if sum == 0:
        break
    elif sum < 0:
        start += 1
    else:   
        end -= 1

print(answer[0], answer[1])
