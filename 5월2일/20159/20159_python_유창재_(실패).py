import sys
input = sys.stdin.readline

N = int(input())
temp_num = list(map(int, input().split()))
odd_num = []
even_num = []

for i in range(N):
    if i % 2 == 0:
        odd_num.append(temp_num[i])
    else:
        even_num.append(temp_num[i])

odd_sum = 0
even_sum = sum(even_num)
result = even_sum

for i in range(int(N/2)):
    odd_sum += odd_num[i]
    even_sum -= even_num[i]
    if result < odd_sum + even_sum:
        result = odd_sum + even_sum

odd_sum = odd_num[0]
even_sum = sum(even_num) - even_num[int(N/2)-1]
if result < odd_sum + even_sum:
    result = odd_sum + even_sum

for i in range(1, int(N/2)-1):
    odd_sum += odd_num[i]
    even_sum -= even_num[i]
    if result < odd_sum + even_sum:
        result = odd_sum + even_sum

print(result)

