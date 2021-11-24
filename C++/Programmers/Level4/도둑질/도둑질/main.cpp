//
//  main.cpp
//  도둑질
//
//  Created by 홍진석 on 2021/06/06.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int dp1[1000001];
int dp2[1000001];

int solution(vector<int> money) {
    
    int answer = 0;
    
    dp1[0] = money.at(0); //1을 털고 시작
    dp1[1] = max(dp1[0],money[1]);
    dp2[1] = money.at(1); //2를 털고 시작

    for(int i=2; i<money.size(); i++){
        dp1[i] = max(dp1[i-2]+money[i],dp1[i-1]);
        dp2[i] = max(dp2[i-2]+money[i],dp2[i-1]);
        
        if(i == money.size()-1){//1을 턴 경우
            dp1[i] = dp1[i-1];
        }
    }
    
    answer = max(dp2[money.size()-1], dp1[money.size()-1]);

    return answer;
}

//도둑이 마을을 턴다
//인접한 두 집을 털면 경보가 울린다.
//각 집에 있는 돈이 담긴 배열 money가 주어질 때, 도둑이 훔칠수 있는 돈의 최댓값 return

int main(){
    vector<int> money;
    
    money.push_back(8);
    money.push_back(2);
    money.push_back(3);
    
    cout << solution(money);
    return 0;
}
