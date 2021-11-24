//
//  main.cpp
//  1890_DP
//
//  Created by 홍진석 on 2021/05/30.
//

#include <iostream>
#include <queue>
using namespace std;

//NxN
//가장 왼쪽 위에서 가장 오른쪽 아래 칸으로 점프
//각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리
//반드시 오른쪽 or 아래쪽 이동
//한번 점프를 할때, 방향을 바꾸면 안된다.
//이동 가능한 경로의 수를 구하시오

int N;
int arr[101][101];
long dp[101][101];


long jump(int x, int y){
    if(x == N-1 && y == N-1){return 1;}//도착하면 return 1
    if(dp[x][y] != -1) return dp[x][y];//Memoization 부분
    
    int num = arr[x][y];//경로 개수
    long cnt = 0;
    
    if(num == 0){return 0;}//경로 개수가 0이면
    if(x + num < N){cnt += jump(x+num,y);} //아래쪽
    if(y + num < N){cnt += jump(x,y+num);} //오른쪽
    
    dp[x][y] = cnt;

    return cnt;
}
int main() {

    cin >> N;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
            dp[i][j] = -1;
        }
    }
   
    cout << jump(0,0);
    
    return 0;
}
