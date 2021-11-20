//
//  main.cpp
//  멀리뛰기
//
//  Created by 홍진석 on 2021/11/19.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long solution(int n) {
    vector<int> v;
    
    vector<int> dp(n+1,0);
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2])%1234567;
    }
    
    return dp[n];
}

int main() {
    cout << solution(4);
    return 0;
}
