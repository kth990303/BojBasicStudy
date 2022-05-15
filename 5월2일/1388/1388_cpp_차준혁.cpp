//22.05.06 #1388 바닥 장식 by HYEOKIKI
#include <iostream>

using namespace std;

char room[50][50];

int main(){
    int N, M; //N은 세로 크기, M은 가로 크기
    char wood; //나무 판떼기
    char temp = '0'; 
    int rowCount = 0; //필요한 '-' 나무 판떼기
    int colCount = 0; //필요한 '|' 나무 판떼기
    cin >> N >> M;

    // '-' 판떼기 세기
    for(int i = 0; i < N; i++){
        temp = '0';
        for(int j = 0; j < M; j++){
            cin >> wood;
            room[i][j] = wood; 
            if(wood == '|'){
                temp = wood;
                continue;
            } 
            if(temp != wood) rowCount += 1;
            temp = wood;
        }
    }
    // '|' 판떼기 세기
    for(int i = 0; i < M; i++){
        temp = '0';
        for(int j = 0; j < N; j++){
            wood = room[j][i];
            if(wood == '-'){
                temp = wood;
                continue;
            } 
            if(temp != wood) colCount += 1;
            temp = wood;
        }
    }
    cout << (rowCount + colCount);

    return 0;
}