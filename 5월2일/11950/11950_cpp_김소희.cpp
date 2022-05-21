#include "bits/stdc++.h"

using namespace std;
// 24463, 24955, 20159
//11950

const int MAX = 51;
char russia[MAX][MAX];
int n, m;
char white[MAX], blue[MAX], red[MAX];
int cnt;
int bl;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> russia[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		white[i] = 'W';
		blue[i] = 'B';
		red[i] = 'R';

	}

	for (int i = 0; i < m; i++)
	{
		if (russia[0][i] != 'W')
			cnt++;
		if (russia[n - 1][i] != 'R')
			cnt++;
	}
	int minc = 51;
	int bc = 0;
	vector<int> b;
	for (int i = 1; i < n - 1; i++)
	{
		bc = 0;
		for (int j = 0; j < m; j++)
		{
			if (russia[i][j] != 'B')
				bc++;
		}
		minc = min(minc, bc);
		if (minc == bc) {
			bl = i;

		}
		b.push_back(minc);
	}
	sort(b.begin(), b.end());
	cnt += b.at(0);
	//중간에 가장 적게 바꿔야하는 blue 찾고 white와 blue 사이, 
	//blue와 red 사이 최소 개수를 찾으면 됨


	cout << cnt;
}