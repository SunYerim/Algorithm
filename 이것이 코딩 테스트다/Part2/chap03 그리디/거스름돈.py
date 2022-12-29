n = 1260
count = 0

money_list = [500, 100, 50, 10]


for money in money_list:
    count += (n // money)
    n %= money


print(count)