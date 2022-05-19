# 팀원 모집

def solution(count):

  if all(visited):
    return count

  minCount = 11
  temp = []
  for i in range(N):
    if not visited[i]:
      for whoSolve in problem[i+1]:
        for canSolve in person[whoSolve]:
          if not visited[canSolve-1]:
            temp.append(canSolve)
            visited[canSolve-1] = True
        minCount = min(minCount,solution(count+1))
        for solved in temp:
          visited[solved-1] = False
        temp = []
  return minCount


N,M=list(map(int,input().split()))
person = [[] for i in range(M)]
problem = {}
visited = [False for i in range(N)]

for i in range(N):
  problem[i+1] = []
for i in range(M):
  temp = input().split()
  person[i]+=list(map(int,temp[1:]))
  for p in temp[1:]:
    problem[int(p)].append(i)

answer = solution(0)
print(answer if answer != 11 else -1)
