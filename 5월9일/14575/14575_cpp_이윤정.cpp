//14575 뒤풀이
/*모든 사람 i가 Li이상 Ri이하의 술을 받으면서,
모든 사람이 받은 술의 총합이 정확히 T가 되고,
어떤 사람도 S를 초과하는 술은 받지 않게 할 수 있는,
S값 중 최솟값 출력, 없으면 -1 출력*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unsigned int N, T, L[1000], R[1000], maxL=0, maxR=0;

    cin >> N >> T;

    for (int i = 0; i < N; i++)
    {
        cin >> L[i] >> R[i];
        maxL = max(maxL, L[i]);
        maxR = max(maxR, R[i]);
    }

    for (unsigned int S = maxL; S <= maxR; S++)
    {
        int minSum = 0, maxSum = 0;
        for (int i = 0; i < N; i++)
        {
            minSum += L[i];
            maxSum += min(S, R[i]);
        }
        if (minSum <= T && T <= maxSum)
        {
            cout << S;
            return 0;
        }
    }
    
    cout << -1;
}