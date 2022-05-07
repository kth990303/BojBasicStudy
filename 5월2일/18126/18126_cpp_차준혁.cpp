//22.05.06 #18126 너구리 구구 by HYEOKIKI
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, long long>> path[5001];

long long dfs(int a, int visited){
    long long result = 0;
    for(int i = 0; i < path[a].size(); i++){
        if(path[a][i].first == visited) continue; //이미 방문했는 지를 체크
        result = max(result, dfs(path[a][i].first, a) + path[a][i].second);
    }
    return result;
}

int main(){

    int N; //N개의 방
    int A,B,C; //A번 방과 B번 방 사이의 길이 C
    cin >> N;
    
    for(int i = 0; i < N - 1; i++){
        cin >> A >> B >> C;
        path[A].push_back({B, C});
        path[B].push_back({A, C});
    }
    cout << dfs(1, -1);

    return 0;
}