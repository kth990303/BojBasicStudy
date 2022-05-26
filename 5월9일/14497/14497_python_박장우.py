# 14497 주난의 난

import sys
from collections import deque
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]


n, m = map(int, input().split())
graph = []
vis = [[-1] * m for _ in range(n)]
x1, y1, x2, y2 = map(int, input().split())
res = 0

for _ in range(n):
    graph.append(list(map(str, input().strip())))


def bfs(sx, sy):
    q = deque()
    q.append((sx, sy))
    vis[sx][sy] = 0

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if (nx < 0 or ny < 0 or nx >= n or ny >= m) or vis[nx][ny] != -1:
                continue

            if graph[nx][ny] == '1' or graph[nx][ny] == '#':
                vis[nx][ny] = vis[x][y] + 1
                graph[nx][ny] = '0'
                q.append((nx, ny))

            elif graph[nx][ny] == '0':
                vis[nx][ny] = vis[x][y]
                q.appendleft((nx, ny))


bfs(x1-1, y1-1)
print(vis[x2-1][y2-1])
