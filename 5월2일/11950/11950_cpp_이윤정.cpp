//11950번 2016 IOI
#include <iostream>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, board[51][3] = { 0 }; //행별 W, B, R 누적합 저장
    char color;
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> color;
            switch (color)
            {
            case 'W': board[i][0]++; break;
            case 'B': board[i][1]++; break;
            case 'R': board[i][2]++; break;
            }
        }
        board[i][0] += board[i - 1][0];
        board[i][1] += board[i - 1][1];
        board[i][2] += board[i - 1][2];
    }

    int maxNoChanges = 0;
    for (int Wends = 1; Wends <= N - 2; Wends++)
        for (int Rstarts = N; Rstarts >= Wends + 2; Rstarts--)
        {
            int noChanges = board[Wends][0] + (board[Rstarts - 1][1] - board[Wends][1]) + (board[N][2] - board[Rstarts - 1][2]);
            if (maxNoChanges < noChanges) maxNoChanges = noChanges;
        }

    cout << N * M - maxNoChanges;
}