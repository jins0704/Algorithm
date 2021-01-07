//
//  main.cpp
//  1149_DP
//
//  Created by 홍진석 on 2020/08/23.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001][3];
int rgb[1001][3];

int main() {
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];
    for(int i=1; i<N; i++){
        dp[i][0] = min({dp[i-1][1],dp[i-1][2]})+rgb[i][0];
        dp[i][1] = min({dp[i-1][0],dp[i-1][2]})+rgb[i][1];
        dp[i][2] = min({dp[i-1][0],dp[i-1][1]})+rgb[i][2];
    }
   
    printf("%d",min({dp[N-1][0],dp[N-1][1],dp[N-1][2]}));
    return 0;
}
