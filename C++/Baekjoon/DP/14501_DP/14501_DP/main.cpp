//
//  main.cpp
//  14501_DP
//
//  Created by 홍진석 on 2021/05/28.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int a,b;
int T[16];
int P[16];
int dp[20];

int main() {
    
    cin >> N;
    
    for(int i = 0; i <N; i++){
        cin >> T[i] >> P[i];
    }
    
    for(int i=0; i<=N; i++){
        for(int j=0; j<i; j++){
            
            dp[i] = max(dp[i],dp[j]);//i날 일을 하지 않을 경우,
            
            if(j+T[j] == i){//일이 종료된 당일 일한다면,
                dp[i] = max(dp[i], dp[j]+P[j]);
            }
        }
    }
    
    cout << dp[N];
    return 0;
}
