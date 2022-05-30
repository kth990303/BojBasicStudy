//11578 팀원 모집
#include <iostream>
using namespace std;

bool OR2Row (int** S, int N, int a, int b)
{
    bool flag = true;
    for (int i = 1; i < N; i++)
    {
        S[0][i] = S[a][i] || S[b][i]; //사용 안하는 0번줄에 결과 기록
        if (!S[0][i]) flag = false;
    }
    return flag;
}

int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, O, P;
    bool S[11][11];
    cin >> N >> M;
    for (int i = 1; i <= M; i++)
    {
        cin >> O; //풀 수 있는 문제 수
        for (int j = 0; j < O; j++)
        {
            cin >> P; //풀 수 있는 문제 번호
            S[i][P] = true; //i번 학생이 P번 문제를 풀 수 있음
        }
    }

    //브루투포스 전부 돌 경우 nC1+nC2+...+nCn = 2^n - 1 (이항정리)
    //n<=10 이므로 최대 2^10 - 1 = 1023

    //조합 구현 어떻게...?
    for (int i = 1; i <= M; i++) //1번부터 M번까지 학생
    {
        for (int j = 1; j <= N; j++)
        {
        }
    }
}