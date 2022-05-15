//24955번 숫자 이어 붙이기
//미완성
#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unsigned long long N, Q, A[1000], a, b, x, y;
    cin >> N >> Q;
    for (int i = 0; i < N; i++) cin >> A[i]; //i번째 집 대문에 적힌 수

    vector<int> T[1001];
    for (int i = 0; i < N - 1; i++) //트리 입력
    {
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }

    for (int i = 0; i < Q; i++)
    {
        cin >> x >> y; //x집부터 y집까지 방문
        //트리에서 두 정점 경로 찾기 -> 공통 조상 나올때까지 양쪽에서 거슬러 올라가...야 될 거 같다고 생각해서 찾아보니까 LCA라는게 있고 그냥 BFSDFS로도 가능은 하다고 해서 좀더 고민해보고 완성하겠습니다
        cout << result % 1000000007 << '\n';
    }
}