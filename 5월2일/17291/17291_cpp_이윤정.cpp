//17291번 새끼치기
#include <iostream>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, count[21] = { 0, 1, 2, 4, 7, };
    cin >> N;
    for (int i = 5; i <= N; i++)
    {
        count[i] = count[i - 1] * 2;
        //죽는 벌레는 4번째 해부터 짝수해마다 발생
        //6번째 해부터 짝수해마다 3년 전 태어난 벌레(4년 전 벌레 수와 동일), 4년 전 태어난 벌레(5년 전 벌레 수와 동일) 사망
        if (i >= 6 && i % 2 == 0)
            count[i] -= count[i - 4] + count[i - 5];
    }
    cout << count[N];
}