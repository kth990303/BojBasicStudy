import sys
input = sys.stdin.readline

n = int(input())
d = [0]*21

d[1] = 1
d[2] = 2
d[3] = 4
d[4] = 7

for i in range(5, 21):
    if i % 2 == 0:
        d[i] = d[i-1] * 2 - d[i-4] - d[i-5]
    else:
        d[i] = d[i-1] * 2

print(d[n])
