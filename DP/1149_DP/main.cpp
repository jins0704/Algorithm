//
//  main.cpp
//  1149_DP
//
//  Created by 홍진석 on 2020/08/23.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int dp[1001][3];
int rgb[1001][3];

int main() {
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }
    dp[0][0] = rgb[0][0];
    dp[0][1] = rgb[0][1];
    dp[0][2] = rgb[0][2];
    for(int i=1; i<N; i++){
        dp[i][0] = min({dp[i-1][1],dp[i-1][2]})+rgb[i][0];
        dp[i][1] = min({dp[i-1][0],dp[i-1][2]})+rgb[i][1];
        dp[i][2] = min({dp[i-1][0],dp[i-1][1]})+rgb[i][2];
    }
   
    printf("%d",min({dp[N-1][0],dp[N-1][1],dp[N-1][2]}));
    return 0;
}

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//int N;
//int dp[1001][3];
//int arr[1001][3];
//
//int minCost(int lastcolor, int arr[]){
//    int minValue = 123456789;
//    for(int i=0; i<3; i++){
//        if(i == lastcolor){continue;}
//        if(arr[i] < minValue){
//            minValue = arr[i];
//        }
//    }
//    return minValue;
//}
//int recursion(int step, int lastcolor){
//
//    if(step == N-1){
//        dp[step][0] = arr[step][0];
//        dp[step][1] = arr[step][1];
//        dp[step][2] = arr[step][2];
//        return minCost(lastcolor, arr[step]);
//    }
//    else{
//        for(int i=0; i<3; i++){
//            if(i== lastcolor){continue;}
//
//            if(dp[step][i] == -1){//저장없다면
//                dp[step][i] = arr[step][i] + recursion(step+1, i);
//            }
//        }
//    }
//
//    return minCost(lastcolor, dp[step]);
//}
//
//int main() {
//
//    cin >> N;
//    for (int i = 0; i < 1001; i++) {
//        fill_n(dp[i], 3, -1);
//    }
//
//    for(int i=0; i<N; i++){
//        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
//    }
//
//    for(int i=0; i<3; i++){
//        cout << recursion(0, i) << endl;
//    }
//    
//    for(int i=0; i<1001; i++){
//        for(int j=0; j<3; j++){
//            cout << dp[i][j] << " ";
//        }cout << endl;
//    }
//    return 0;
//}
