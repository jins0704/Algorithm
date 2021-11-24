//
//  main.cpp
//  2806_DP
//
//  Created by 홍진석 on 2021/07/24.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1000001][2];
string s;

int main() {
    cin >> N;
    cin >> s;
    
    //dp[N][0] = N번째까지 A로 만드는 수
    //dp[N][1] = N번째까지 B로 만드는 수
    if(s[0] == 'A'){
        dp[0][0] = 0;
        dp[0][1] = 1;
    }
    else{
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    
    for(int i=1; i<N; i++){
        if(s[i] == 'A'){
            dp[i][0] = min(dp[i-1][0], dp[i-1][1]+1);//A로 만들기
            dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]+1);//B로 만들기
        }
        
        else{
            dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1]+1);
            dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]);
        }
    }
    
    cout << dp[N-1][0];
    return 0;
}

