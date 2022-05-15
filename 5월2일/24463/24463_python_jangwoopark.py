from collections import deque
import sys
input = sys.stdin.readline
INF = -1

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


def init(vis):
    for i in range(n):
        for j in range(m):
            if graph[i][j] == '+':
                vis[i][j] = INF


def bfs(a, b, vis):
    q = deque()
    q.append((a, b))
    vis[a][b] = 1

    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            if graph[nx][ny] == '+' or vis[nx][ny] != 0:
                continue

            vis[nx][ny] = vis[x][y] + 1
            q.append((nx, ny))


n, m = map(int, input().split())
graph = []
vis1 = [[0]*m for _ in range(n)]
vis2 = [[0]*m for _ in range(n)]
res = [[0]*m for _ in range(n)]


for _ in range(n):
    graph.append(list(input().rstrip()))

in_out = []

for i in range(n):
    if graph[i][0] == '.':
        in_out.append((i, 0))

    elif graph[i][m-1] == '.':
        in_out.append((i, m-1))


for i in range(m):
    if graph[0][i] == '.':
        in_out.append((0, i))
    elif graph[n-1][i] == '.':
        in_out.append((n-1, i))

sx, sy, ex, ey = in_out[0][0], in_out[0][1], in_out[1][0], in_out[1][1]

init(vis1)
init(vis2)
bfs(sx, sy, vis1)
bfs(ex, ey, vis2)

for i in range(n):
    for j in range(m):
        res[i][j] = vis1[i][j] + vis2[i][j]


for i in range(n):
    for j in range(m):
        if res[i][j] > 0 and res[sx][sy] != res[i][j]:
            graph[i][j] = '@'
        if res[i][j] == 0:
            graph[i][j] = '@'

for i in range(n):
    for j in range(m):
        print(graph[i][j], end='')
    print()
