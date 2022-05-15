//22.05.06 #17291 새끼치기 by HYEOKIKI
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; //N년
    cin >> N;
    vector<int> insectVec; //각 원소는 벌레이면서 그 벌레의 분열가능한 숫자를 원소를 가짐.
    insectVec.push_back(3); 
    int insectNum = insectVec.size();
    for(int year = 2; year <= N; year++){
        for(int i = 0; i < insectVec.size(); i++) insectVec[i] -= 1;
        if(year%2 == 0){
            for(int i = 0; i < insectNum; i++) insectVec.push_back(4);
        }
        else{
            for(int i = 0; i < insectNum; i++) insectVec.push_back(3);
        }
        insectNum = 0;
        for(int i = 0; i < insectVec.size(); i++){
            if(insectVec[i] > 0) insectNum += 1;
        }
    }
    cout << insectNum;
    return 0;
}