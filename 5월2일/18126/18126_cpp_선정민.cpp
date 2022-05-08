
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int MAX = 5001;
int N;
vector<pair<int, int>> line[MAX];
int check[MAX];
long long int max_cost;

void dfs(int start, long long int cost) {
    check[start] = 1;
    max_cost = max(max_cost, cost);
    for (int i = 0; i < line[start].size(); i++) {
        int x = line[start][i].first;
        if (check[x] == 0) {
            check[x] = 1;
            dfs(x, cost + line[start][i].second);
        }
    }
}

int main() {
    cin.tie();
    cout.tie();
    cin >> N;
    for (int i = 1; i < N; i++) {
        int x, y, cost;
        cin >> x >> y >> cost;
        line[x].push_back({ y,cost });
        line[y].push_back({ x,cost });
    }
    dfs(1,0);
    cout << max_cost << '\n';
}