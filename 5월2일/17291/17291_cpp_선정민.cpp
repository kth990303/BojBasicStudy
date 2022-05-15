#include <iostream>

using namespace std;

int n;
int worms[21] = {1,1,2,4,7};


// 짝수해 홀수해 구분

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 4; i < n; i++)
    {
        worms[i+1] = worms[i] * 2;
        //[i-3] 은 홀수년도, [i-4]는 짝수년도에 새로 태어난 개체의 수.
        if((i-2) % 2 == 1)
            worms[i+1] -= worms[i-3];
        if((i-3) % 2 == 0)
            worms[i+1] -= worms[i-4];
    }

    cout << worms[n] << '\n';
}
