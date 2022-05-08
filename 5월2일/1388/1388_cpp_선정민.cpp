
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

const int MAX = 51;
int n, m;
char graph[MAX][MAX];
bool visited[MAX][MAX];

int main()
{
    cin.tie();
    int count = 0;
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> graph[i][j];

    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 이미 방문했던 곳이라면 무시
            if(visited[i][j] == true) continue;
            count++;
            visited[i][j] = true; // 방문 표시

            if(graph[i][j] == '-')
            {
                // - 의 경우 '|'가 나올떄까지 열을 돌며 방문 표시
                for(int k = j+1; k < m; k++)
                {
                    if(graph[i][k] == '|') break;
                    visited[i][k] = true;
                }
            }
            else
            {
                // |의 경우 - 가 나올때까지 행을 돌며 방문 표시
                for(int k = i + 1; k < n; k++)
                {
                    if(graph[k][j] == '-') break;
                    visited[k][j] = 1;
                }
            }
        }
    }

    cout << count << '\n';
}