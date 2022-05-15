import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline


n = int(input())
graph = [[] for _ in range(n+1)]
vis = [False] * (n+1)
res = []
for i in range(n-1):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))
    graph[b].append((a, c))


def dfs(node, cur):
    vis[node] = True

    for next_node in graph[node]:
        if not vis[next_node[0]]:
            dfs(next_node[0], cur + next_node[1])
            res.append(cur+next_node[1])


dfs(1, 0)

if len(res) == 0:
    print(0)
else:
    print(max(res))
