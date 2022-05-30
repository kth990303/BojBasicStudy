//23888번 등차수열과 쿼리

#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long a, d, q, flag, l, r;
    cin >> a >> d >> q;
    while (q--)
    {
        cin >> flag >> l >> r;
        if (flag == 1)
        {
            long long Al = a + (l - 1) * d;
            long long Ar = a + (r - 1) * d;
            cout << (Al + Ar) * (r - l + 1) / 2 << "\n";
        }
        if (flag == 2)
        {
            if (l == r) cout << a + (l - 1) * d << "\n";
            else cout << gcd(a, d) << "\n";
            //30점: 모든 항에 대해 gcd 연산 수행했음
            //초항, 공차에 대해 gcd 구하면 항상 되는 이유??
            //a+d, a+3d -> a+d, 2d -> ?
        }
    }
}