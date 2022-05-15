#include "bits/stdc++.h"

using namespace std;
//   24463, 17291, 24955, 20159
//18126,11950,
int n, s;
const int MAX = 20001;
int cow[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> cow[i];

	}
	sort(cow, cow+n);
	int st = 0, e = n - 1;
	while (st < e) {
		if (cow[st] + cow[e] <= s)
			cnt = cnt + e - st;
		else {
			e -= 1;
			st -= 1;
		}
		st += 1;
	}
	cout << cnt;
}