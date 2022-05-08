# 시간 초과......

import sys

sys.setrecursionlimit(4*1000000)
input=sys.stdin.readline

def dfs(pos):
  if pos == endHole:
    answer[pos[0]-1][pos[1]-1] = '.'
    return True
  
  flag = False
  y,x = pos

  for i in range(4):
    if miro[y+ny[i]][x+nx[i]]=='.' and not visited[y+ny[i]-1][x+nx[i]-1]:
      visited[y+ny[i]-1][x+nx[i]-1] = True
      flag = flag or dfs([y+ny[i],x+nx[i]])

  if flag:
    answer[pos[0]-1][pos[1]-1] = '.'
  return flag

def findHole():
  holes=[]
  for i in range(1,N+1):
    if miro[i][1] == '.':
      holes.append([i,1])
    if miro[i][M] == '.':
      holes.append([i,M])

  for i in range(1,M+1):
    if miro[1][i] == '.':
      holes.append([1,i])
    if miro[N][i] == '.':
      holes.append([N,i])
  
  return holes

N,M = list(map(int,input().split()))
miro = [[0 for i in range(M+2)]]
answer = []
visited = [[False for i in range(M)] for j in range(N)]

nx = [0,-1,1,0]
ny = [-1,0,0,1]

for i in range(N):
  temp = list(input().replace('\n',''))
  miro.append([0]+temp[:]+[0])
  answer.append([])
  for t in temp:
    answer[-1].append('@' if t == '.' else t)
miro+=[[0 for i in range(M+2)]]

startHole, endHole = findHole()
visited[startHole[0]-1][startHole[1]-1] = True
dfs(startHole)

for row in answer:
  for col in row:
    print(col,end="")
  print()

