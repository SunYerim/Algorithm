'''금액 조합 만든 후 price에 append => count 생성 후 price list 길이만큼 돌리고, count+1 하며
    일치하는 숫자 있는지 탐색 '''
N = int(input())

coin = list(map(int, input().split()))
#coin.sort()

price = []
# slicing .. => 조합 추가
for i in range(N):
    for j in range (i+1, N+1):
        price.append(sum(coin[i:j]))

price.sort()
count = 1

while True:
    if count not in price:
        break;
    elif count in price:
        count += 1

print(count)

'''
1 1 2 3 9 // 1+1+2+3=7
현재까지 더한 값과 다음에 올 값 사이 간격이 없으면 okay
간격이 있으면 만들 수 없는 숫자
'''