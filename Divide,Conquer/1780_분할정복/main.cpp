//
//  main.cpp
//  1780_분할정복
//
//  Created by 홍진석 on 2020/07/26.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;
int cnt[3];
int arr[2187][2187];
void ccheck(int x, int y, int N){
    int tmp = arr[x][y];
    int check=0;
    
    if(N==1){
        if(tmp == -1) cnt[0]++;
        if(tmp == 0) cnt[1]++;
        if(tmp == 1) cnt[2]++;
        return;
    }
    for(int i=x; i<x+N; i++){
        for(int j= y; j< y+N; j++){
            if(arr[i][j] == tmp){check++;}
        }
    }
    if(check == N*N || N==1){
        if(tmp == -1) cnt[0]++;
        if(tmp == 0) cnt[1]++;
        if(tmp == 1) cnt[2]++;
        return;
    }
    ccheck(x, y, N/3);
    ccheck(x+N/3, y, N/3);
    ccheck(x+2*N/3, y, N/3);
   
    ccheck(x, y+N/3, N/3);
    ccheck(x+N/3, y+N/3, N/3);
    ccheck(x+2*N/3, y+N/3, N/3);
    
    ccheck(x, y+2*N/3, N/3);
    ccheck(x+N/3, y+2*N/3, N/3);
    ccheck(x+2*N/3, y+2*N/3, N/3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>> arr[i][j];
        }
    }
    ccheck(0,0,N);
    for(int i=0; i<3; i++){
        cout << cnt[i] <<endl;
    }
    return 0;
}
