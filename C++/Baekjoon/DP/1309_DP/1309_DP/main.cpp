//
//  main.cpp
//  1309_DP
//
//  Created by 홍진석 on 2021/04/05.
//

#include <iostream>

using namespace std;

//가로 2칸, 세로 N칸
//사자는 가로세로 붙어있게 배치 x

int N;
int dp[100001][3]; // i j 중 j=0, 둘다없음, j=1, 왼쪽있음, j=2, 오른쪽있음
int main() {
    
    cin >> N;
    
    dp[0][0] = 1;
    dp[0][1] = 1;
    dp[0][2] = 1;
    for(int i=1; i<N; i++){
        dp[i][0] = ((dp[i-1][0] + dp[i-1][1] + dp[i-1][2]))%9901;
        dp[i][1] = ((dp[i-1][0] + dp[i-1][2]))%9901;
        dp[i][2] = ((dp[i-1][0] + dp[i-1][1]))%9901;
    }
    
    int a = (dp[N-1][0] + dp[N-1][1] + dp[N-1][2])%9901;
    cout << a << endl;
    return 0;
}
