//
//  main.cpp
//  2798_BruteForce
//
//  Created by 홍진석 on 2020/07/17.
//  Copyright © 2020 홍진석. All rights reserved.
//

//참여자 : 정민, 상근, 창영 3명
// 양의 정수 . N 장의 카드 보이도록 놓는다. 숫자 M을 외친다.
// N장의 카드 중 3장 고름. M을 넘으면 안된다.

#include <iostream>

using namespace std;

int main() {
    int n,m,sum=0;
    int goal =0;
    cin >> n >> m;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    for(int i=0; i<n-2; i++){
        for(int j=i+1; j<n-1; j++){
            for(int k = j+1; k<n; k++){
                sum= arr[i]+arr[j]+arr[k];
                if(sum<=m && goal<sum){
                    goal= sum;
                }
            }
        }
    }
    cout << goal;
    return 0;
}
