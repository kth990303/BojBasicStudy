count, size = list(map(int, input().split()))
cows = []
answer = 0

for i in range(count):
  cows.append(int(input()))

cows.sort()

s, e = 0, count-1

while s < e:
  if cows[s]+cows[e]<=size:
    answer += e-s
    s += 1
  else:
    e -= 1
    
print(answer)
