'''logic
    1. 다장조는 c d e f g a b C
    2. 각각 1 2 3 4 5 6 7 8 
    '''

da = [1, 2, 3, 4, 5, 6, 7, 8]
da2 = [8, 7, 6, 5, 4, 3, 2, 1]
music = list(map(int, input().split()))

if music == da:
    print('ascending')
elif music == da2:
    print('descending')
else:
    print('mixed')

