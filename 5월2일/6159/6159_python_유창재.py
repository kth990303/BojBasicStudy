import sys
input = sys.stdin.readline

n, s = map(int, input().split())
cow = []
result = 0

for _ in range(n):
    cow.append(int(input()))

for i in range(n-1):
    for j in range(i+1,n):
        if s - cow[i] >= cow[j]:
            result += 1

print(result)
