#include "bits/stdc++.h"

using namespace std;
//11578, 14497, 15976, 1953, 20313, 20955, 24391, 5859
vector<int> can_solve[11];		//index번 학생이 풀 수 있는 문제
vector<int> team;
int problem, people, val, num, result = 11;

void dfs(int cnt, int idx) {		//포함한 사람 수, 이후 사람
	if (cnt >= result) return;		//현재 저장된 값보다 많은 수의 사람이 필요한 경우 return
	if (cnt > 0) {
		bool solved[11] = { false, };
		for (int i = 0; i < cnt; i++) {
			int cidx = team[i];
			//현재 팀으로 풀 수 있는 문제 검사
			for (int j = 0; j < can_solve[cidx].size(); j++)
				solved[can_solve[cidx][j]] = true;
		}
		bool avail = true;
		for (int i = 1; i <= problem; i++) {
			if (!solved[i]) {
				avail = false;
				break;
			}
		}
		//모든 문제를 풀 수 있다면 최소 팀원 갱신
		if (avail)
			result = min(result, cnt);
	}
	if (idx > people) return;
	for (int i = idx; i <= people; i++) {
		team.push_back(i);
		dfs(cnt + 1, i + 1);
		team.pop_back();
	}
}

int main() {
	cin >> problem >> people;
	for (int i = 1; i <= people; i++) {
		cin >> val;
		for (int j = 0; j < val; j++) {
			cin >> num;
			can_solve[i].push_back(num);
		}
	}
	dfs(0, 1);
	if (result == 11) result = -1;
	cout << result;
	return 0;
}