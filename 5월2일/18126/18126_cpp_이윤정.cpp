//18126번 너구리 구구
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct NODE
{
    int dest;
    long long dist;
    NODE(int dest, long long dist) : dest(dest), dist(dist) {};
};

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, A, B;
    long long C, result = 0;
    vector<NODE> G[5001];
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        cin >> A >> B >> C;
        G[A].push_back(NODE(B, C));
        G[B].push_back(NODE(A, C));
    }
    stack<NODE> S;
    bool visited[5001] = { 0 };
    S.push(NODE(1, 0));
    while (!S.empty())
    {
        NODE now = S.top();
        S.pop();
        if (!visited[now.dest])
        {
            visited[now.dest] = true;
            if (G[now.dest].size() == 1 && now.dest != 1)
            {
                if (now.dist > result)
                    result = now.dist;
            }
            else
            {
                for (auto it = G[now.dest].begin(); it != G[now.dest].end(); ++it)
                    S.push(NODE(it->dest, now.dist + it->dist));
            }
        }
    }
    cout << result;
}