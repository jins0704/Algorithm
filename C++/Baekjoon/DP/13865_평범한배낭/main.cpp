//
//  main.cpp
//  13865_평범한배낭
//
//  Created by 홍진석 on 2021/11/18.
//

#include <iostream>
#include <vector>

using namespace std;

int dp[101][100001];
int W[101];
int V[101];

int main() {
    int N = 0;
    int K = 0;
    
    cin >> N >> K;
    
    for(int i=1; i<=N; i++){
        cin >> W[i] >> V[i];
    }
    
    
    for(int i=1; i<= N; i++){
        for(int j = 1; j<=K; j++){
            
            if(j-W[i] >= 0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
            }
            else{ dp[i][j] = dp[i-1][j]; }
        }
    }
    
    cout << dp[N][K];
    return 0;
}

//N개의 물건
//각 물건은 무게 W, 가치 V
//최대 K만큼의 무게
//가치의 최댓값 구하기

