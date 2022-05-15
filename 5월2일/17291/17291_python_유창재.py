import sys
input = sys.stdin.readline

N = int(input())

bug_list = [0, 1, 2, 4, 7]

if N < 5:
    print(bug_list[N])
else:
    for i in range(5, N+1):
        if i % 2 == 0:
            bug_list.append(bug_list[i-1] + bug_list[i-2] + bug_list[i-3])
        else:
            bug_list.append(bug_list[i-1] + bug_list[i-2] + bug_list[i-3] + bug_list[i-4])

    print(bug_list[N])


