from collections import deque
import sys
input = sys.stdin.readline

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
n, m = map(int, input().split())
graph = []
vis = [[0]*m for _ in range(n)]
cnt = 1

for _ in range(n):
    graph.append(list(input().rstrip()))


def bfs(a, b, num):

    q = deque()
    q.append((a, b))
    vis[a][b] = num

    while q:
        x, y = q.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx == n or ny == m:
                continue

            if vis[nx][ny] != 0:
                continue

            if graph[x][y] == '-':
                if graph[nx][ny] == graph[x][y] and i >= 2:
                    vis[nx][ny] = num
                    q.append((nx, ny))
            else:
                if graph[nx][ny] == graph[x][y] and i < 2:
                    vis[nx][ny] = num
                    q.append((nx, ny))


for i in range(n):
    for j in range(m):
        if vis[i][j] == 0:
            bfs(i, j, cnt)
            cnt += 1

res = 0
for i in range(n):
    for j in range(m):
        res = max(res, vis[i][j])

print(res)
