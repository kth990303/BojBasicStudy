import sys
input = sys.stdin.readline
sys.setrecursionlimit(10000)

N, M = map(int, input().split())
wood_list = []
stack = [[0, _] for _ in range(M-1, -1, -1)]
queue = [[0, _] for _ in range(M)]
result = 0

for _ in range(N):
    wood_list.append(input())


def wood_dfs(wood):
    global M, N
    global stack
    global wood_list
    global result

    if len(stack) == 0:
        return 0

    i, j = stack.pop()
    tempwood = wood_list[i][j]

    if i < N-1:
        stack.append([i+1, j])
        if wood != '|' and tempwood == '|':
            result += 1
            wood_dfs(tempwood)
        else:
            wood_dfs(tempwood)
    else:
        if wood != '|' and tempwood == '|':
            result += 1
            wood_dfs(None)
        else:
            wood_dfs(None)


def wood_bfs(wood):
    global M, N
    global queue
    global wood_list
    global result

    if len(queue) == 0:
        return 0

    i, j = queue.pop(0)
    tempwood = wood_list[i][j]

    if j < M-1:
        if i < N-1:
            queue.append([i+1, j])
        if wood != '-' and tempwood == '-':
            result += 1
            wood_bfs(tempwood)
        else:
            wood_bfs(tempwood)
    else:
        if i < N-1:
            queue.append([i+1, j])
        if wood != '-' and tempwood == '-':
            result += 1
            wood_bfs(None)
        else:
            wood_bfs(None)


wood_dfs(None)
wood_bfs(None)
print(result)


