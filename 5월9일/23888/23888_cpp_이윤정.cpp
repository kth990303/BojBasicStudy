//23888�� ���������� ����

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
            //30��: ��� �׿� ���� gcd ���� ��������
            //����, ������ ���� gcd ���ϸ� �׻� �Ǵ� ����??
            //a+d, a+3d -> a+d, 2d -> ?
        }
    }
}