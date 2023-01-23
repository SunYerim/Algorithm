'''logic
    "누적" => 케이스 쪼개서 생각함.
    1. 각 줄의 양 끝에 있는 숫자들은 바로 윗 줄의 숫자를 더해주면 된다.
    2. 사이에 있는 숫자는 왼쪽 대각선과 오른쪽 대각선 중 최댓값에 더해나가면 된다.
    3. 결국은 최댓값 찾고 누적합.
    '''

n = int(input())
num = []

for i in range(n):
    num.append(list(map(int, input().split())))

# 맨 꼭대기는 for문 돌릴필요 없음.
for i in range(1, n):
    for j in range(len(num[i])):
        # 각 라인의 제일 첫 숫자
        if j == 0:
            num[i][j] = num[i][j] + num[i-1][j]
        # 각 라인의 제일 마지막 숫자
        elif j == len(num[i])-1:
            num[i][j] = num[i][j] + num[i-1][j-1]
        # 위의 경우 제외한 나머지 경우
        else:
            num[i][j] = max(num[i-1][j-1], num[i-1][j]) + num[i][j]

# 맨 마지막 줄(누적합)에서 최댓값 출력
print(max(num[n-1]))
