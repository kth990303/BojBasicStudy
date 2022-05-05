N = int(input())
cards = list(map(int,input().split()))
oddSums,evenSums = [cards[0]],[cards[1]]

for i in range(2,N):
  if i % 2 == 0:
    oddSums.append(oddSums[-1]+cards[i])
  else:
    evenSums.append(evenSums[-1]+cards[i])

maxTotal = max(oddSums[-1],evenSums[-1])
if N>=4:
  maxTotal = max(maxTotal,oddSums[0]+evenSums[-2])
for i in range(2,N-1):
  if (i+1)%2==1:
    maxTotal = max(maxTotal,oddSums[(i+1)//2-1]+evenSums[-1]-evenSums[(i+1)//2-1])
  else:
    maxTotal = max(maxTotal,oddSums[(i+1)//2-1]+evenSums[-2]-evenSums[(i+1)//2-2])
  
print(maxTotal)
