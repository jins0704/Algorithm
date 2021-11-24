//
//  main.cpp
//  1904_DP
//
//  Created by 홍진석 on 2021/03/28.
//

#include <iostream>

using namespace std;

// 00,1 타일

int N;
int dp[10000001];
int main() {
    
    cin >> N;
    
    dp[1] = 1; //1
    dp[2] = 2; //11, 00
    dp[3] = 3; //111, 001, 100
    dp[4] = 5; //1111, 0011, 1001, 1100, 0000
    dp[5] = 8; //11111,00111, 10011, 11001, 11100, 00001, 00100, 10000
    
    for(int i=3; i<=N; i++){
        dp[i] = (dp[i-1] + dp[i-2])%15746;
    }
    
    cout << dp[N];
    return 0;
}
