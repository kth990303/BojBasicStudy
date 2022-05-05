//6159 : 코스튬 파티
//굳이 누적합으로 할 필요가 있을까??
//완료
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, S, cnt;
vector<int> cows;


int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		cows.push_back(temp);
	}

	sort(cows.begin(), cows.end());

	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (cows[i] + cows[j] <= S) {
				cnt++;
			}
			else {
				break;
			}
		}
	}
	cout << cnt;
	return 0;
}
//#include<iostream>
//#include<vector>
//#include<algorithm>
//
//using namespace std;
//
//int N, S, cnt;
//vector<int> cows;
//vector<int> pref;
//
//
//int main() {
//	cin >> N >> S;
//	for (int i = 0; i < N; i++) {
//		int temp = 0;
//		cin >> temp;
//		cows.push_back(temp);
//	}
//
//	sort(cows.begin(), cows.end());
//
//	pref.push_back(cows[0]);
//	for (int i = 0; i < N-1; i++) {
//		pref.push_back(pref[i] + cows[i + 1]);
//	}
//
//	for (int i = 0; i < pref.size(); i++) {
//		cout << pref[i] << " / ";
//	}
//	cout << cnt;
//	return 0;
//}
