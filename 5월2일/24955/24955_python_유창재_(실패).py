import sys
import math
input = sys.stdin.readline
sys.setrecursionlimit(1000)

n, q = map(int, input().split())
door_num = list(map(int, input().split()))
load = []
stack = []
number_queue = []
room_checker = [0 for _ in range(n+1)]

for _ in range(n-1):
    a, b = map(int, input().split())
    load.append([a, b])
    load.append([b, a])


def room_dfs(index, destination):
    global n, q
    global door_num
    global load
    global stack
    global numbers
    global room_checker

    for row in load:
        if row[0] == index and room_checker[row[1]] == 0:
            stack.append(row[1])
            room_checker[row[1]] = 1

    number_queue.append(door_num[index-1])

    if destination == index:
        return 0

    next_index = stack.pop(0)
    room_dfs(next_index, destination)


for _ in range(q):
    number_queue = []
    room_checker = [0 for _ in range(n + 1)]
    stack = []
    result = 0
    MOD = 1000000007

    start, destination = map(int, input().split())
    room_checker[start] = 1
    room_dfs(start, destination)

    for num in number_queue:
        l = int(math.log10(num)) + 1
        result = (result * 10 ** l % MOD + num % MOD) % MOD

    print(result)

