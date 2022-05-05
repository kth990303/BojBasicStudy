
#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
char graph[201][201];
int visited[201][201];

int main()
{
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
            if(visited[i][j] == 1) continue;
            count++;
            visited[i][j] = 1; // 방문 표시

            // 현재 모양을 저장
            char shape = graph[i][j];
            if(shape == '-')
            {
                // - 의 경우 '|'가 나올떄까지 열을 돌며 방문 표시
                for(int k = j+1; k < m; k++)
                {
                    if(graph[i][j] == '|') break;
                    visited[i][j] = 1;
                }
            }
            else
            {
                // |의 경우 - 가 나올때까지 행을 돌며 방문 표시
                for(int k = i + 1; k < n; k++)
                {
                    if(graph[i][j] == '-') break;
                    visited[i][j] = 1;
                }
            }
        }
    }

    cout << count << '\n';
    return 0;
}