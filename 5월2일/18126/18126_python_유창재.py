import sys
input = sys.stdin.readline
sys.setrecursionlimit(5000)

N = int(input())
room_list = []
queue = []
distance = [0 for _ in range(N+1)]
room_checker = [0 for _ in range(N+1)]

for _ in range(N-1):
    A, B, C = map(int, input().split())
    room_list.append([A, B, C])
    room_list.append([B, A, C])


def room_bfs(index):
    global N
    global room_list
    global queue
    global distance

    for row in room_list:
        if row[0] == index and room_checker[row[1]] == 0:
            queue.append([row[1], distance[index] + row[2]])
            room_checker[row[1]] = 1

    if len(queue) == 0:
        return 0
    i, s = queue.pop(0)
    if distance[i] < s:
        distance[i] = s

    room_bfs(i)


room_checker[1] = 1
room_bfs(1)
print(max(distance))
