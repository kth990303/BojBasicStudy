count, size = list(map(int, input().split()))
cows = []
answer = 0

for i in range(count):
  cows.append(int(input()))

for i in range(count-1):
  for j in range(i+1,count):
    if cows[i]+cows[j]<=size:
      answer+=1

print(answer)
