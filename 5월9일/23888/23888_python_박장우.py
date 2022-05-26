# 23888 등차수열과 쿼리
import sys
input = sys.stdin.readline


def gcd(a, b):
    if a == 0:
        return b

    return gcd(b % a, a)


a, d = map(int, input().split())
q = int(input())
for _ in range(q):
    query, l, r = map(int, input().split())
    a_l = a + (l - 1) * d

    if query == 1:
        s_l = (2 * a + (l - 1) * d) * l // 2
        s_r = (2 * a + (r - 1) * d) * r // 2
        print(s_r - s_l + a_l)
        
        # 30점 받은 코드: int 형변환 문제?
        # s_l = (2 * a + (l - 1) * d) * l / 2
        # s_r = (2 * a + (r - 1) * d) * r / 2
        # print(int(s_r - s_l) + a_l)

    else:
        if l == r:
            print(a_l)
        else:
            print(gcd(a, d))
