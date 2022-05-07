//22.05.06 #6159 코스튬 파티 by HYEOKIKI
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, S; //N은 소의 수, S는 코스튬의 크기
    cin >> N >> S;
    int cowCount = N;
    int result = 0;
    vector<int> cowVec(N, 0);
    int index = 0;
    while(N--){
        cin >> cowVec[index++];
    }

    sort(cowVec.begin(), cowVec.end());

    for(int leftIndex = 0; leftIndex < cowCount; leftIndex++){
        int rightIndex = cowCount-1;
        if(cowVec[leftIndex] > int(S/2)) break;
        while((cowVec[leftIndex] + cowVec[rightIndex]) > S) rightIndex -= 1;
        result += (rightIndex - leftIndex);
    }

    cout << result;

    return 0;
}