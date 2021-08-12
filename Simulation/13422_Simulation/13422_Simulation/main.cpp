//
//  main.cpp
//  13422_Simulation
//
//  Created by 홍진석 on 2021/08/12.
//

#include <iostream>
#include <vector>
#include <queue>

#define FOR(i,n) for(int i=0; i<(n); i++)

using namespace std;

int T;
int N,M,K,m;

int main() {
    cin >> T;
    vector<int> cntV;
    while(T--){
        cin >> N >> M >> K;
        vector<int> v;
        
        FOR(i, N){
            cin >> m;
            v.push_back(m);
        }
        int cnt = 0;
        int money = 0;
        queue<int> stealMoney;
        
        FOR(i, M){
            stealMoney.push(v[i]);
            money += v[i];
        }
        
        if(money < K){ cnt ++; }
        
        if(M != N){
            for(int i= 0; i<v.size()-1; i++){
                int idx = i+M;
                if(idx >= v.size()){
                    idx = i+M - int(v.size());
                }
                money -= stealMoney.front();
                stealMoney.pop();
                money += v[idx];
                stealMoney.push(v[idx]);\
                if(money < K){ cnt ++; }
            }
        }
    
        cntV.push_back(cnt);
    }
    
    FOR(i, cntV.size()){
        cout << cntV[i] << endl;
    }
    return 0;
}

//마을 사람들은 각자 자신의 집에 돈을 보관
//집에 적혀있는 숫자는 돈의 금액
//M개의 연속된 집에서 돈을 훔친다.
//K원 이상 훔친다면, 도둑은 잡힌다.

// 집의 개수 N, 연속된 집의 개수 M
// 방범장치 작동하는 최송 돈의 양 K
// 도둑이 잡히지 않고 돈을 훔칠 M개의 연속된 집을 고르는 방법의 수 출력

// 첫째줄 테스트개수 T
// 집의 개수 N, 훔칠 집 M , 최소돈 K 공백을 구분
// N개의 집에서 보관중인 돈이 시계방향 순서대로 공백으로 구분

