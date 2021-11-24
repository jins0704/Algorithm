//
//  main.cpp
//  11053_DP
//
//  Created by 홍진석 on 2021/03/12.
//

#include <iostream>
#include <algorithm>

using namespace std;

//수열 A 가장 긴 증가하는 부분 수열
//수열 A 크기는 N
//수열 A 정보는 Ai

int N;
int arr[1001];
int dp[1001];

int main() {
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
        dp[i] = 1;
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j< i; j++){
           
            if(arr[i] > arr[j]){
               
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
                
            }
        }
    }
    
    int sol = 0;
    
    for(int i=0; i<N; i++){
        if(dp[i] > sol) {
            sol = dp[i];
        }
    }
    
    cout << sol;
    return 0;
}
