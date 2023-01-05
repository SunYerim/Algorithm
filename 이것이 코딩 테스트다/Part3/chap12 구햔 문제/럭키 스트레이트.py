num = input()
num_len = len(num)

left = 0
right = 0

# 앞쪽과 뒷쪽 합이 같다 
for i in range(num_len // 2):
    left += int(num[i])

for i in range(num_len // 2, num_len):
    right += int(num[i])

if (left == right):
    print("LUCKY")
else:
    print("READY")




