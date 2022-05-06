//24463번 미로
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> XY;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M;
    char maze[2001][2001];
    vector<XY> hole;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '.')
                if (i == 0 || i == N - 1 || j == 0 || j == M - 1) hole.push_back(make_pair(i, j));
        }

    //돌아오는 길이 존재x 즉 회로x -> 트리 -> 각 노드에 부모정보만 저장한 뒤 거슬러 올라가서 루트까지 경로 찾기
    //첫번째 hole에서부터 maze배열에 대고 4방향 확인하며 DFS/BFS로 그래프(트리) 입력
    XY parent[2001][2001];
    queue<XY> Q;
    Q.push(hole[0]);
    while (!Q.empty())
    {
        XY now = Q.front();
        Q.pop();
        int ways[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (int i = 0; i < 4; i++)
        {
            int x = now.first + ways[i][0];
            int y = now.second + ways[i][1];
            if (0 <= x && x < N && 0 <= y && y < M && maze[x][y] == '.')
            {
                Q.push(make_pair(x, y));
                parent[x][y] = now;
                maze[x][y] = '@'; //모든 . 미리 @로 변경해두고 경로만 .로 다시 수정, visited 체크도 가능
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (maze[i][j] == '.') maze[i][j] = '@'; //연결 안된채로 . 표시인 것 존재

    //방문 확인 출력
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //        cout << maze[i][j];
    //    cout << '\n';
    //}

    //경로 표시
    XY now = hole[1];
    while (now != hole[0])
    {
        maze[now.first][now.second] = '.';
        now = parent[now.first][now.second];
    }
    maze[now.first][now.second] = '.';

    //출력
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            cout << maze[i][j];
        cout << '\n';
    }
}