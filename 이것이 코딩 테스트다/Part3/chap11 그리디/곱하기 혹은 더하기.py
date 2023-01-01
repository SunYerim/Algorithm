'''case 분류 => 0, 1이 나오는 경우는 +가 유리 / 나머지는 *'''
#문자열 입력받음
number = input()

# 첫번째 판단 기준 숫자 (total = 1로 하려했으나, 그렇게되면 첫 문자가 0인경우 케이스 배제됨.)
total = int(number[0])

#문자열 길이만큼 반복
for i in range(1, len(number)):
    num = int(number[i])
    if (num <= 1 or total <=1):
        total += num
    else:
        total *= num

print(total)