import sys
input = sys.stdin.readline

n, s = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))
arr.sort()

cnt = 0
st, en = 0, n-1

while st < en:
    if arr[st] + arr[en] <= s:
        cnt += (en-st)
        st += 1
    else:
        en -= 1


print(cnt)
