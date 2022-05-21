# 20313: 출퇴근
# 실패: 틀렸습니다가 계속 뜨는데 이유를 모르겠습니다.

import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)


n, m, a, b = map(int, input().split())
graph = [[] for _ in range(n+1)]
distance = [INF] * (n+1)
road_info = [[] for _ in range(m)]
res = INF


for i in range(m):
    u, v, t = map(int, input().split())
    road_info[i].append((u, v))
    graph[u].append((v, t))
    graph[v].append((u, t))

k = int(input())
data = []
for _ in range(k):
    data.append(list(map(int, input().split())))


def dijkstra(start):

    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:

        dist, cur = heapq.heappop(q)

        if dist > distance[cur]:
            continue

        for node in graph[cur]:
            cost = dist + node[1]

            if cost < distance[node[0]]:
                distance[node[0]] = cost
                heapq.heappush(q, (cost, node[0]))


dijkstra(a)
res = min(res, distance[b])

for i in range(k):
    graph = [[] for _ in range(n+1)]
    distance = [INF] * (n+1)
    for j in range(m):
        u, v, t = road_info[j][0][0], road_info[j][0][1], data[i][j]
        graph[u].append((v, t))
        graph[v].append((u, t))

    dijkstra(a)
    res = min(res, distance[b])


print(res, end='')
