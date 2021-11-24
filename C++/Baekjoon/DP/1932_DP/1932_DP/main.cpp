//
//  main.cpp
//  1932_DP
//
//  Created by 홍진석 on 2021/03/12.
//

#include <iostream>
#include <algorithm>

using namespace std;

// 크기 - n
// 맨위층에서부터 하나를 선택해서 내려올 때 이제까지 선택된 수의 합이 최대가 되는 경로를 구해라
// 현재층에서 선책된 수의 대각선 왼쪽 또는 대각선 오른쪽 중에서만 선택할 수 있다.

int n;
int arr[501][501];
int dp[501][501];

int main() {
    
    cin >> n;
    

    for(int i=0; i<n; i++){
        for(int j= 0; j<=i; j++){
            cin >> arr[i][j];
        }
    }
    
    dp[0][0] = arr[0][0];
    dp[1][0] = dp[0][0] + arr[1][0];
    dp[1][1] = dp[0][0] + arr[1][1];
    
    for(int i=2; i<n; i++){
        dp[i][0] = dp[i-1][0] + arr[i][0];
        dp[i][i+1] = dp[i-1][i] + arr[i][i+1];
        
        for(int j=1; j<=i; j++){
            dp[i][j] = max(dp[i-1][j-1],dp[i-1][j]) + arr[i][j];
        }
    }
    
    int sol = 0;
    
    for(int i=0; i<n; i++){
        if(sol < dp[n-1][i]){
            sol = dp[n-1][i];
        }
    }
    
    cout << sol;
    return 0;
}
