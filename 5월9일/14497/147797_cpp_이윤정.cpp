//14497 주난의 난
//메모리초과...?
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> XY;

char cell[301][301];
int ways[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
queue<XY> Q;

int BFS(int N, int M)
{
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
                    break;
                case '0':
                    Q.push(make_pair(x, y));
                    break;
                case '#':
                    return true;
                }
            }
        }
    }
    return false;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, x1, y1, x2, y2, count = 0;

    cin >> N >> M;
    cin >> x1 >> y1 >> x2 >> y2;
    for(int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            cin >> cell[i][j];
    bool founded = false;
    while (!founded)
    {
        Q.push(make_pair(x1, y1));
        founded = BFS(N, M);
        count++;
        /*cout << endl;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
                cout << cell[i][j];
            cout << endl;
        }*/
    }
    if (count != 1) count++;
    cout << count;
}