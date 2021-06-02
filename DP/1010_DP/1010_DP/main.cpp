//
//  main.cpp
//  1010_DP
//
//  Created by 홍진석 on 2021/06/02.
//

#include <iostream>

using namespace std;

int N,M,T;
long dp[31][31];

long combination(int m, int n){
    if(n==m || n == 0){return 1;}
    if(dp[m][n] != 0){return dp[m][n];}
    
    dp[m][n] = combination(m-1,n-1) + combination(m-1, n);
    
    return dp[m][n];
}

int main() {
    
    cin >> T;
    
    while(T--){
        
        cin >> N >> M;
        cout << combination(M, N) << endl;
    }
    
    return 0;
}
