# 14575 뒤풀이
import sys
input = sys.stdin.readline
INF = int(1e9)


n, t = map(int, input().split())
arr = []


def is_possible(s):
    # remain: 사람들이 최소 주량만큼 마신다 가정 했을 때 더 마실 수 있는 양
    # min_sum: 모든 사람들의 최소 주량 합
    remain, min_sum = 0, 0

    for i in range(n):

        if arr[i][0] > s:
            return False

        # remain = ((최대 주량 혹은 s값 중 작은 값) - (최소 주량)) 의 합
        remain += (min(arr[i][1], s) - arr[i][0])
        min_sum += arr[i][0]

    # t - min_sum = 사람들이 더 마셔야 하는 양
    if remain >= t - min_sum:
        return True

    return False


left, right = 0, 0
min_num, max_num = 0, 0
res = INF

for _ in range(n):
    l, r = map(int, input().split())
    min_num += l
    max_num += r
    right = max(right, r)
    arr.append((l, r))

# 불가능한 경우
if min_num > t or max_num < t:
    print(-1)
    exit()


while left <= right:
    s = (left + right) // 2
    if is_possible(s):
        res = min(res, s)
        right = s - 1
    else:
        left = s + 1


print(res)
