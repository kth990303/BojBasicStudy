#include "bits/stdc++.h"

using namespace std;
// 14497, 15976, 1953, 20313, 20955, 24391, 5859
int n;
vector<int> blue, white;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int cnt;
		cin >> cnt;
		if (i == 1) {
			blue.push_back(i);
			for (int j = 0; j < cnt; j++)
			{
				int s;
				cin >> s;
			}
		}
		else {
			int sum = 0;
			for (int j = 0; j < cnt; j++)
			{
				int hate;
				cin >> hate;
				auto it1 = find(blue.begin(), blue.end(), hate);
				auto it2 = find(white.begin(), white.end(), hate);
				
					if (it1 == blue.end()&&sum==0) {
						blue.push_back(i);
						sum++;
					}
					if (it2 == white.end()&&sum==0) {
						white.push_back(i);
						sum++;
					}
					if(sum==0)
						blue.push_back(i);
				
				
			}
		}
	}
	
	sort(blue.begin(), blue.end());
	sort(white.begin(), white.end());
	if (white.size() == 0) {
		blue.erase(blue.begin() + 1);
		white.push_back(1);
	}if (blue.size() == 0) {
		white.erase(white.begin() + 1);
		blue.push_back(1);
	}
	cout << blue.size() << endl;
	for (int i = 0; i < blue.size(); i++)
	{
		cout << blue.at(i) << " ";
	}
	cout << endl << white.size() << endl;
	for (int i = 0; i < white.size(); i++)
	{
		cout << white.at(i) << " ";
	}

}