//
//  main.cpp
//  등굣길
//
//  Created by 홍진석 on 2021/06/06.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[101][101];
long dp[101][101];

long start(int n, int m){
    //cout << n << " " << m << endl;
    if(n == 1 && m == 1){return 1;}
    
    if(dp[n][m] != 0){ return dp[n][m];}
    
    if(arr[n-1][m] != 1 && n-1 >= 1){
        dp[n][m] += start(n-1,m);
    }
    if(arr[n][m-1] != 1 && m-1 >= 1){
        dp[n][m] += start(n,m-1);
    }
    
    return dp[n][m]%1000000007;
}
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    for(int i=0; i<puddles.size(); i++){
        arr[puddles[i].at(1)][puddles[i].at(0)] = 1; //물에 잠긴 곳
    }
    
    answer = int(start(n,m));
    
    return answer;
}

//물에 잠기지 않은 지역을 통해 학교 등교
//m x n 격자모양 -> m : 가로 , n : 세로
//(1,1)집 ~ (m,n)학교
//오른쪽과 아래쪽으로만 움직여서 학교를 갈 수 있는 최단 경로의 개수를 1,000,000,007로 나눈 나머지 return
//puddles - 물에 잠긴 지역

int main() {
    
    vector<int> puddle1;
    puddle1.push_back(2);
    puddle1.push_back(2);
    
    vector<int> puddle2;
    puddle2.push_back(2);
    puddle2.push_back(3);
    
    vector<vector<int>> puddles;
    puddles.push_back(puddle1);
    puddles.push_back(puddle2);
    
    
    
    cout << solution(4, 3, puddles);
    
//    cout << "arr" << endl;
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            cout << arr[i][j] << " ";
//        }cout << endl;
//    }
//
//    cout << "dp" << endl;
//    for(int i=1; i<=n; i++){
//        for(int j=1; j<=m; j++){
//            cout << dp[i][j] << " ";
//        }cout << endl;
//    }
    return 0;
}
