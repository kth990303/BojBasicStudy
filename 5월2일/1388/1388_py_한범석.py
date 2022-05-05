def horizontal(x, y, maxX):
  for i in range(x,maxX):
    if tiles[y][i] == '|':
      break
    visited[y][i] = True

def vertical(x, y, maxY):
  for i in range(y,maxY):
    if tiles[i][x] == '-':
      break
    visited[i][x] = True

maxY,maxX = list(map(int,input().split()))
tiles = []
visited=[[False for i in range(maxX)] for j in range(maxY)]
answer = 0

for i in range(maxY):
  tiles.append(list(input()))
for i in range(maxX):
  for j in range(maxY):
    if not visited[j][i]:
      answer += 1
      if tiles[j][i] == '-':
        horizontal(i,j,maxX)
      else:
        vertical(i,j,maxY)

print(answer)
