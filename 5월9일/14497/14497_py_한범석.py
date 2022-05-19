#주난의난

import sys

N,M = list(map(int,input().split()))
junanX,junanY,criminalX,criminalY = list(map(int,input().split()))

classRoom = []
distance = [[-1 for j in range(M)] for i in range(N)]
nx=[-1,0,0,1]
ny=[0,-1,1,0]

for i in range(N):
  classRoom.append(list(input()))

pos = [[junanX-1,junanY-1]]
distance[junanX-1][junanY-1] = 0
while pos:
  nowX,nowY = pos.pop(0)
  for i in range(4):
    newX,newY = nowX+nx[i],nowY+ny[i]
    if not (0<=newX<N and 0<=newY<M):
      continue
    if distance[newX][newY] == -1:
      if classRoom[newX][newY] == '#' or classRoom[newX][newY] == '1':
        distance[newX][newY] = distance[nowX][nowY]+1
        pos.append([newX,newY])
      elif classRoom[newX][newY] == '0':
        distance[newX][newY] = distance[nowX][nowY]
        pos.insert(0,[newX,newY])
  
print(distance[criminalX-1][criminalY-1])
