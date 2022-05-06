import sys
sys.setrecursionlimit(5002)

def dfs(now,total):
  maxLength = total
  for i in range(1,len(edge[now])):
    if edge[now][i] and not visited[i]:
      visited[i] = True
      maxLength = max(maxLength,dfs(i,total+edge[now][i]))
  return maxLength

N = int(input())
edge = [[0 for i in range(N+1)] for i in range(N+1)]
for i in range(N-1):
  a, b, c = list(map(int,input().split()))
  edge[a][b]=c
  edge[b][a]=c

visited = [False for i in range(N+1)]
visited[1] = True
print(dfs(1,0))
