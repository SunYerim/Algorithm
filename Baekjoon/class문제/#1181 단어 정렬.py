n = int(input())

word = []
for _ in range(n):
    words = input()
    word.append(words)

#중복제거
word = list(set(word))

word.sort(key = lambda x: (len(x), x))

for i in range(len(word)):
    print(word[i])