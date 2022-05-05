#include "bits/stdc++.h"

using namespace std;
//   6159, 18126, 11950, 24463, 17291, 24955, 20159
int n, s;
vector<int> v;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		int l;
		cin >> l;
		v.push_back(l);
	}
	sort(v.begin(), v.end());
	int cnt=0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (v.at(i) + v.at(j) <= s)cnt++;
		}
	}
	cout << cnt;
}