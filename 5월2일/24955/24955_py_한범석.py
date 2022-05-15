REMAIN = 1000000007
N,Q = list(map(int,input().split()))
A = list(map(int,input().split()))
road = [[] for i in range(N)]
plays = []
for i in range(N-1):
  a,b = list(map(int,input().split()))
  road[a-1].append(b-1)
  road[b-1].append(a-1)

for i in range(Q):
  plays.append(list(map(int,input().split())))

for start,end in plays:
  visited = [False for i in range(N)]
  visited[start-1]=True
  stack = [[start-1,A[start-1]]]
  answer = ''
  while stack:
    node,string = stack.pop()
    if node == end-1:
      answer = string
      break
    for i in road[node]:
      if not visited[i]:
        visited[i]=True
        stack.append([i,(string*10**(len(str(A[i])))%REMAIN+A[i]%REMAIN)%REMAIN])
  print(answer)
