//1388번 바닥장식
#include <iostream>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char woodboard;
    int N, M, count = 0;
    bool wasHorizontal = false, wasVertical[50] = { 0 };
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> woodboard;
            if (woodboard == '-')
            {
                wasVertical[j] = false;
                if (!wasHorizontal) count++;
                wasHorizontal = true;
            }
            else //woodboard == '|'
            {
                wasHorizontal = false;
                if (!wasVertical[j]) count++;
                wasVertical[j] = true;
            }
        }
        wasHorizontal = false;
    }
    cout << count;
}