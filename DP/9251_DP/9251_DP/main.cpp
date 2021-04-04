//
//  main.cpp
//  9251_DP
//
//  Created by 홍진석 on 2021/03/14.
//

#include <iostream>
#include <algorithm>

using namespace std;

//LCS 최장 공통 부분 수열
//모두의 부분 수열이 되는 수열중 가장 긴 것
string sen1;
string sen2;

int dp[1001][1001];
int maxValue;
int main() {
    cin >> sen1;
    cin >> sen2;
    
    for(int i=0; i<sen2.size(); i++){
        for(int j=0; j<sen1.size(); j++){
            if(sen2[i] == sen1[j]){
                dp[i][j]++;
                if(i>0 && j>0){
                    dp[i][j] += dp[i-1][j-1];
                }
            }
            else{
                if(i>0 && j>0){
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                else if (i == 0 && j > 0) {
                    dp[i][j] = dp[i][j-1];
                }
                else if (j == 0 && i > 0) {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
    }
 
    cout << dp[sen2.size()-1][sen1.size()-1];
    return 0;
}

// i 입장에서  j 만남
//0 입장에서 1 만남
//1 입장에서 0 만남,  2 만남
//2 입장에서 5 만남
//3 입장에서 1 만남
//4 입장에서 0 만남,  2 만남
//5 입장에서 4 만남
