# 팀 배분

def dfs(i,flag):
  result[i] = flag
  visited[i] = 1
  for j in range(1,N+1):
    if j in hater[i] and not visited[j]:
      dfs(j, -flag)

N = int(input())
hater = {}
visited = [0 for i in range(N+1)]
result = [0 for i in range(N+1)]

for i in range(N):
  hater[i+1] = list(map(int,input().split()[1:]))

for i in range(1,N+1):
  if not visited[i]:
    dfs(i,1)

print(result.count(1))
for i in range(1,N+1):
    if result[i] == 1:
        print(i, end=" ")
print()
print(result.count(-1))
for i in range(1,N+1):
    if result[i] == -1:
        print(i, end=" ")
print()
