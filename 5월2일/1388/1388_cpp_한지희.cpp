//1388 : �ٴ� ���
//dfs �̿�
//board�� max������ �̸� ����� ���� �ʰ� �Է��� �޾� ����� ��찡 ���� ��

#include<iostream>

using namespace std;

const int MAX = 51;
int N, M, cnt;
char board[MAX][MAX];
int visited[MAX][MAX]{ 0 };
char now;

void dfs(char n, int i, int j) {
	if (board[i][j] != now) return;
	visited[i][j] = 1;
	if (board[i][j] == '-') {
		if (j + 1 < M) {
			if (!visited[i][j + 1]) {
				dfs(now, i, j + 1);
			}
		}
	}
	else if (board[i][j] == '|') {
		if (i + 1 < N) {
			if (!visited[i + 1][j]) {
				dfs(now, i + 1, j);
			}
		}
	}
	return;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			//�湮���κ��� Ȯ��
			if (!visited[i][j]) {
				visited[i][j] = 1;
				cnt++;
				if (board[i][j] == '-') {
					now = '-';
					dfs(now, i, j + 1);
				}
				else if (board[i][j] == '|') {
					now = '|';
					dfs(now, i + 1, j);
				}
			}
		}
	}

	cout << cnt << "\n";


	return 0;
}