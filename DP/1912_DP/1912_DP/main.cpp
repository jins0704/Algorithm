//
//  main.cpp
//  1912_DP
//
//  Created by 홍진석 on 2021/04/04.
//

#include <iostream>
#include <algorithm>

using namespace std;

// n개의 정수
// 몇개 선택해서 가장 큰 합

int arr[100001];
int dp[100001];
int N;

int main() {
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    dp[0] = arr[0];
    int maxValue = dp[0];
    
    for(int i=1; i<N; i++){
        dp[i] = max(dp[i-1] + arr[i], arr[i]);
        
        if(maxValue < dp[i]){
            maxValue = dp[i];
        }
    }
    cout << maxValue;
    
    return 0;
}
