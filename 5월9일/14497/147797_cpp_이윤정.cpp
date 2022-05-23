//14497 주난의 난
//메모리초과... -> visited 관리 안해서 q에 계속 들어감
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> XY;

char cell[301][301];
int ways[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int BFS(int N, int M, XY Junan)
{
    queue<XY> Q;
    bool visited[301][301] = { 0, }; //방문여부를 각 점프별로 관리해야 함
    //이전 점프의 방문여부가 다음 점프에 영향을 주면 안되기 때문에
    //cell에 직접 기록 시 문제 발생

    Q.push(Junan);
    while (!Q.empty())
    {
        XY now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = now.first + ways[i][0];
            int y = now.second + ways[i][1];
            if (1 <= x && x <= N && 1 <= y && y <= M && !visited[x][y])
            {
                visited[x][y] = true;
                switch (cell[x][y])
                {
                case '1':
                    cell[x][y] = '0';
                    break;
                case '0':
                    Q.push(make_pair(x, y));
                    break;
                case '#':
                    cell[x][y] = 'x';
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
        founded = BFS(N, M, make_pair(x1,y1));
        count++;
        /*cout << endl;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= M; j++)
                cout << cell[i][j];
            cout << endl;
        }*/
    }
    cout << count;
}