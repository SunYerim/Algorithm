
while True:
    num = input()

    if num == '0':
        break

    # 역순 출력
    if num == num[::-1]:
        print('yes')
    else:
        print('no')