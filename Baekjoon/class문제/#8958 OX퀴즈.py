n = int(input())
list1 = []

for quiz in range(n):
    quiz = input()
    score = 0
    total = 0

    for ox in quiz:
        if ox == 'O':
            score += 1
            total += score
        else:
            score = 0
    print(total)