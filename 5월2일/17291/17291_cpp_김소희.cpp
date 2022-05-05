#include "bits/stdc++.h"

using namespace std;
//   24463, 17291, 24955, 20159
//18126,11950,
int n;
const int MAX = 21;
int bug[MAX];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n; 
	bug[1] = 1;
	bug[2] = 2;
	bug[3] = 4;
	bug[4] = 7;
	for (int i = 5; i < MAX; i++)
	{
		bug[i] = 2 * bug[i - 1];
		if (i % 2 == 0) {
			bug[i] = bug[i] - bug[i - 4] - bug[i - 5];
		}
	}
	cout << bug[n];


}