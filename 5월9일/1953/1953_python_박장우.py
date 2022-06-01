# 1953: 팀배분

import sys
from collections import deque
input = sys.stdin.readline


n = int(input())
graph = [[] for _ in range(n+1)]
vis = [0] * (n+1)

# team[0] = 청팀, team[1] = 백팀
team = [[] for _ in range(2)]

for i in range(1, n+1):
    data = list(map(int, input().split()))
    for j in range(1, data[0]+1):
        graph[i].append(data[j])


def is_one_sided(arr):
    if len(arr) == n:
        print(n-1)
        for i in range(n-1):
            print(arr[i], end=' ')

        print()
        print(1)
        print(arr[-1])
        exit()


def bfs(start):
    q = deque()
    q.append(start)
    vis[start] = 1

    while q:
        cur = q.popleft()

        for person in graph[cur]:
            if vis[person] != 0:
                continue

            if vis[cur] == 1:
                vis[person] = -1
            elif vis[cur] == -1:
                vis[person] = 1

            q.append(person)


for i in range(1, n+1):
    if not vis[i]:
        bfs(i)


for i in range(1, n+1):
    if vis[i] == 1:
        team[0].append(i)
    else:
        team[1].append(i)

team[0].sort()
team[1].sort()


is_one_sided(team[0])
print(len(team[0]))
print(*team[0])
print(len(team[1]))
print(*team[1])
