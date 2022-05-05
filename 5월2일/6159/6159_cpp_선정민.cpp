
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, s;
int cows[20001];
int cnt = 0;

int main()
{
    cin >> n >> s ;
    for(int i = 0; i < n; i++)
        scanf("%d", &cows[i]);

    sort(cows,cows+n);
    for(int i = 0; i < n-1; i++)
    {
        if (cows[i] > s)
            break;
        for (int j = i + 1; j < n; j++) {
            if(cows[i] + cows[j] <= s)
                cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}