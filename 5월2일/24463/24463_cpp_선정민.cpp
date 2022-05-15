#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

char miro[2002][2002];
bool visited[2002][2002];
int n, m;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> miro[i][j];
        }
    }

}