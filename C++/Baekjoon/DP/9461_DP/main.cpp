//
//  main.cpp
//  9461_DP
//
//  Created by 홍진석 on 2020/07/28.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
using namespace std;

long dp[100];
long sol[100];
void solution(int t){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    dp[6] = 3;
    dp[7] = 4;
    dp[8] = 5;
    dp[9] = 7;
    dp[10] = 9;
    for(int i=11; i<= t; i++){
        dp[i] = dp[i-1]+ dp[i-5];
    }
}
int main(){
    int T,t;
    cin >> T;
    for(int i=0; i<T; i++){
        cin >> t;
        solution(t);
        sol[i] = dp[t];
    }
    for(int i=0; i<T; i++){
        cout << sol[i] << endl;
    }
    return 0;
}
