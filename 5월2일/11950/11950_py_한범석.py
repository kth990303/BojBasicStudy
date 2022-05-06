def dfs(i,color,count):
  if i == N-1:
    if color!='W':
      return count
    else:
      return N*M
  minCount = N*M
  if color == 'W':
    minCount = min(minCount,dfs(i+1,'W',count+M-W[i]))
    minCount = min(minCount,dfs(i+1,'B',count+M-B[i]))
  elif color == 'B':
    minCount = min(minCount,dfs(i+1,'B',count+M-B[i]))
    minCount = min(minCount,dfs(i+1,'R',count+M-R[i]))
  else:
    remain = sum([M-R[j] for j in range(i,N-1)])
    minCount = min(minCount,dfs(N-1,'R',count+remain))
  return minCount

N, M = list(map(int,input().split()))
W,B,R = [],[],[]
for i in range(N):
  w,b,r=0,0,0
  for s in input():
    if s == 'W':
      w+=1
    elif s == 'B':
      b+=1
    else:
      r+=1
  W.append(w)
  B.append(b)
  R.append(r)

answer=M-W[0]+M-R[N-1]
answer+=dfs(1,'W',0)
print(answer)
