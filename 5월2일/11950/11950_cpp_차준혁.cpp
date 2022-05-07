//22.05.06 #11950 2016 IOI by HYEOKIKI
#include <iostream>

using namespace std;

char flag[50][50];

int makeFlag(int wIndex, int rIndex, int N, int M){
    int count = 0;
    for(int row = 0; row <= wIndex; row++){
        for(int col = 0; col < M; col++){
            if(flag[row][col] != 'W') count += 1;
        }
    }
    for(int row = wIndex + 1; row < rIndex; row++){
        for(int col = 0; col < M; col++){
            if(flag[row][col] != 'B') count += 1;
        }
    }
    for(int row = rIndex; row < N; row++){
        for(int col = 0; col < M; col++){
            if(flag[row][col] != 'R') count += 1;
        }
    }

    return count;
}

int main(){
    int N, M; //N줄 M개의 문자열
    int result = 2501;

    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> flag[i][j];
        }
    }
    //windex 줄까지 흰색, rIndex줄부터 마지막까지 빨간색
    for(int wIndex = 0; wIndex < N-2; wIndex++){
        for(int rIndex = wIndex + 2; rIndex < N; rIndex++){
            int temp = makeFlag(wIndex, rIndex, N, M);
            result = min(result, temp);
        }
    }

    cout << result;

    return 0;    
}
