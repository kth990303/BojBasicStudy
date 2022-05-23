//14497 주난의 난
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> XY;

char cell[301][301];
int ways[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
queue<XY> Q;

int BFS(int x, int y, int N, int M, int count)
{
    count++;
    Q.push(make_pair(x, y));
    while (!Q.empty())
    {
        XY now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = now.first + ways[i][0];
            int y = now.second + ways[i][1];
            if (1 <= x && x <= N && 1 <= y && y <= M)
            {
                switch (cell[x][y])
                {
                case '1':
                    cell[x][y] = '0';
                    count = BFS(x, y, N, M, count);
                    break;
                case '0':
                    Q.push(make_pair(x, y));
                    break;
                case '#':
                    return count;
                }
            }
        }
    }
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, x1, y1, x2, y2;

    cin >> N >> M;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> cell[i][j];
    cout << BFS(x1, y1, N, M, 0);
}