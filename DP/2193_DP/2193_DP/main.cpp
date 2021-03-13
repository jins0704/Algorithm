//
//  main.cpp
//  2193_DP
//
//  Created by 홍진석 on 2021/03/13.
//

#include <iostream>

using namespace std;

//이친수 0으로 시작하지 않는다
//1이 두번 연속으로 나타나지않는다.

int N;
long dp[91];

int main() {
    
    cin >> N;
        
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    
    cout << dp[N-1];
    return 0;
}
