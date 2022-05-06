//6159번 코스튬 파티
#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, S, cowSizes[20000], count = 0;
    cin >> N >> S;
    for (int i = 0; i < N; i++)
        cin >> cowSizes[i];
    sort(cowSizes, cowSizes + N);
    int i = 0, j = N - 1;
    while (i < j)
    {
        if (cowSizes[i] + cowSizes[j] <= S)
        {
            count += j - i;
            j = N - 1;
            i++;
        }
        else j--;
    }
    cout << count;
}