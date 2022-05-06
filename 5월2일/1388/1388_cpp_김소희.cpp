#include "bits/stdc++.h"

using namespace std;
//  1388, 6159, 18126, 11950, 24463, 17291, 24955, 20159
const int MAX = 51;
int n, m;
char b[MAX][MAX];
int visited[MAX][MAX];
char now = '-';
int cnt;

void dfs(int i, int j) {
	if (b[i][j] != now)return;
	visited[i][j] = 1;
	if (b[i][j] == '-') {
		if (j + 1 < m) {
			if (!visited[i][j + 1]) {
				dfs(i, j + 1);
			}
		}
	}
	else if (b[i][j] == '|') {
		if (i + 1 < n) {
			if (!visited[i + 1][j]) {
				dfs(i + 1, j);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j]) {
				visited[i][j] = 1;
				cnt++;
				if (b[i][j] == '-') {
					if (j + 1 < m) {
						if (!visited[i][j + 1]) {
							now = '-';
							dfs(i, j + 1);
						}
					}
				}
				else if (b[i][j] == '|') {
					if (i + 1 < n) {
						if (!visited[i + 1][j]) {
							now = '|';
							dfs(i + 1, j);
						}
					}
				}
			}
		}
	}

	cout << cnt;

}