import sys
input = sys.stdin.readline

N, M = map(int, input().split())  # N, M 행 열 입력 받음
flag_list = []

for _ in range(N): # 현재 칠해져있는 깃발 색상 입력 받음.
    flag_list.append(input())

for row in range(N):  # 문자열을 W B R 개수로 단순화
    W = 0
    B = 0
    R = 0
    for color in flag_list[row]:  # 이 부분을 간단히 할 수 있는 파이썬 코드가 있을 것 같다...
        if color == 'W':
            W += 1
        elif color == 'B':
            B += 1
        elif color == 'R':
            R += 1
    flag_list[row] = [W, B, R]

white_sum = M - flag_list[0][0]  # 맨 처음 색질해야 되는 색깔 수 맨 윗줄만 W, 맨 아랫줄만 R
blue_sum = 0
for row in range(1,N-1):
    blue_sum += M - flag_list[row][1]
red_sum = M - flag_list[N-1][2]
result = white_sum + blue_sum + red_sum

for i in range(1,N-2):
    temp_blue_sum = blue_sum
    temp_red_sum = red_sum
    for j in range(N-2, i, -1):
        temp_blue_sum -= M - flag_list[j][1]
        temp_red_sum += M - flag_list[j][2]
        tempsum = white_sum + temp_blue_sum + temp_red_sum
        if tempsum < result:
            result = tempsum
    white_sum += M - flag_list[i][0]
    blue_sum -= M - flag_list[i][1]
    tempsum = white_sum + blue_sum + red_sum
    if tempsum < result:
        result = tempsum

print(result)
