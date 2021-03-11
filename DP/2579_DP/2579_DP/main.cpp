//
//  main.cpp
//  2579_DP
//
//  Created by 홍진석 on 2021/03/11.
//

#include <iostream>
#include <algorithm>

using namespace std;

// 계단오르기
// 계단 시작점부터 도착점 가는 게임
// 계단을 밟으면 계단 점수 얻음
// 한번에 1~2 계단씩 오를 수 있다.
// 연속된 세개의 계단을 모두 밟으면 안된다.(시작점 제외)
// 계단은 300이하의 자연수, 점수는 10000이하

int score[1001];
int dp[1001];

int main() {

    int N;
    
    cin >> N;
    
    for(int i=1; i<=N; i++){
        cin >> score[i];
    }
    
    dp[0] = 0;
    dp[1] = score[1];
    dp[2] = score[1] + score[2];
    
    for(int i=3; i<=N; i++){
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }
    
    cout << dp[N];
    return 0;
}
