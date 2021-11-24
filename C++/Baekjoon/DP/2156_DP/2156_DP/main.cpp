//
//  main.cpp
//  2156_DP
//
//  Created by 홍진석 on 2021/03/13.
//

#include <iostream>
#include <algorithm>

using namespace std;

//포도주 잔을 선택하면 모두 마시고 원래 위치에 놓는다.
//연속된 3잔을 모두 마실수 없다.
//1-n 각 포도주 양이 주어질 때 가장 많은 포도주를 마실 수 있는 프로그램

int arr[10001]; //포도주 양
int dp[10001]; // n번째까지 가장 많이 마신 양과 연속 체크 수

int n;

int main() {
    
    cin >> n;
    
    for(int i=1; i<=n; i++){

        cin >> arr[i];

    }

    dp[1] = arr[1];
    dp[2] = dp[1] + arr[2];
    
    for(int i=3; i<=n; i++){
     
        dp[i] = max(dp[i-3]+arr[i]+arr[i-1], dp[i-2]+arr[i]);
        dp[i] = max(dp[i-1], dp[i]);
        
    }
    
    cout << dp[n];
    
    return 0;
}
