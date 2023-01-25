t = int(input())

for row in range(t):
    num, word = input().split()
    text = ''
    for i in word:
        text += int(num) * i
    print(text)