#include "bits/stdc++.h"

using namespace std;
// 24463, 24955, 20159
//18126,11950,
int n;
const int MAX = 5001;
vector<pair<int, int>> house[MAX];
long long int m;
int check[MAX];

void dfs(int start,long long int cost) {
	check[start] = 1;
	m = max(m, cost);
	for (int i = 0; i < house[start].size(); i++)
	{
		int x = house[start][i].first;
		if (check[x] == 0) {
			check[x] = 1;
			dfs(x, cost + house[start][i].second);
		}
	}

}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int a, b, cost;
		cin >> a >> b >> cost;
		house[a].push_back({ b,cost });
		house[b].push_back({ a,cost });
	}

	dfs(1, 0);

	cout << m;
}