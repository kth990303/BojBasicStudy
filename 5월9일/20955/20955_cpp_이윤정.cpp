//20955 민서의 응급 수술
//무방향, 연결보장x, 회로존재 그래프 -> 트리
//segfault...
#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, u, v, count = 0, visitedNum = 0;
    cin >> N >> M;

    //입력의 양이 방대하므로 빠른 입력 사용 권장...
    bool G[100001][100001] = { 0, };
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        G[u][v] = true;
        G[v][u] = true;
    }

    queue<int> Q;
    bool Visited[100001] = { 1, 0, };

    int now = 1;
    while (!Q.empty() || visitedNum < N )
    {
        if (!Q.empty()) Q.pop();
        if (!Visited[now]) //방문 전이면
        {
            Visited[now] = true; //방문
            visitedNum++;
            for (int i = 1; i <= N; i++)
                if (G[now][i])
                {
                    Q.push(i); //연결된 것들 push
                    G[i][now] = false; //거꾸로 돌아오는 길 삭제...?
                }
        }
        else //이미 방문했는데 또 연결되어 있던거면
            count++; //끊어줌

        if (Q.empty())
        {
            for(int i = 1; i <= N; i++) //연결된 것 없으면
                if (!Visited[i]) //끊긴것들 중 방문 안한 것 찾아서
                {
                    now = i;
                    count++; //이어줌
                    break;
                }
        }
        else
        {
            now = Q.front();
            //Q.pop();
        }
    }
    cout << count;
}