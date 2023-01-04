#N -> 볼링공의 개수, M -> 공의 최대 무게
N, M = map(int, input().split())
balling = list(map(int, input().split()))

'''두 사람은 서로 무게가 다른 공을 골라야 함.'''
count = 0
for i in range(N):
    for j in range(i+1, N):
        if (balling[i] != balling[j]):
            count += 1

print(count)