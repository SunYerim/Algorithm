'''case 분류 => 0, 1이 나오는 경우는 +가 유리 / 나머지는 *'''
#문자열 입력받음
number = input()

# 첫번째 판단 기준 숫자 
# 첫 문자 0 들어오는 경우 생각
total = int(number[0])

#문자열 길이만큼 반복
for i in range(1, len(number)):
    num = int(number[i])
    if (num <= 1 or total <=1):
        total += num
    else:
        total *= num

print(total)
