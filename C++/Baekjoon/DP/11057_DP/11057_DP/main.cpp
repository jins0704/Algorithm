//
//  main.cpp
//  11057_DP
//
//  Created by 홍진석 on 2021/05/30.
//

#include <iostream>

using namespace std;

int dp[1001][10]; //길이, 숫자
int N;

int main() {
    
    cin >> N;
    
    for(int i=0; i<10; i++){
        dp[1][i] = 1;
    }
    if(N > 1){
        for(int i=2; i<=N; i++){
            for(int j=0; j<10; j++){
                for(int k=0; k<=j; k++){
                    dp[i][j] += dp[i-1][k]%10007;
                }
            }
        }
    }
  
    int sum =0;
    for(int j=0; j<10; j++){
        sum += dp[N][j]%10007;
    }
    
    cout << sum%10007;
    
    
    return 0;
}

