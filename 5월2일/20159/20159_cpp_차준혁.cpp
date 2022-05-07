//22.05.06 #20159 동작 그만. 밑장 빼기냐? by HYEOKIKI 틀림
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; //N은 카드의 개수
    cin >> N;
    long long result = 0;
    vector<int> cardVec;
    int temp;
    for(int i = 0; i < N; i++){
        cin >> temp;
        cardVec.push_back(temp);
    }

    //밑빼 안한 경우
    for(int j = 0; j < N; j++){
        if (j%2 == 0){
            result += cardVec[j];
        }
    }

    //밑빼 한 경우
    for(int i = 0; i < N-1; i++){
        if(i % 2 == 0) continue;
        long long temp = 0;
        temp += cardVec[N-1];
        bool flag = true;
        for(int j = 0; j < N-1; j++){
            if((j == i) && (j % 2 == 0)){
                flag = false;
                continue;
            }
            if (flag){
                temp += cardVec[j];
                flag = false;
            }
            else{
                flag = true;
            }
        } 
        result = max(temp, result);
    }
    
    cout << result;

    return 0;
}