#거짓말쟁이

N,M = list(map(int,input().split()))
edge = {}
graph = []
where = [-1 for i in range(N)]

for i in range(M):
  x,y,f = input().split()
  if x not in edge.keys():
    edge[int(x)]=[]
  edge[int(x)].append(int(y))

for x,y in edge.items():
  if where[x-1] == -1:
    graph.append([])
    where[x-1] = len(graph)-1
  here = where[x-1]

  for i in y:
    if where[i-1] == -1:
      graph[here].append(i)
      where[i-1] = here
    else:
      temp = graph[where[i-1]]
      while temp:
        p = temp.pop()
        


