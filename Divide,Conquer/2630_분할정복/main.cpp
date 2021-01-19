//
//  main.cpp
//  2630_분할정복
//
//  Created by 홍진석 on 2020/07/26.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int A[200][200];
int cnt[2];

void cut(int x, int y, int N){
    int tmp = A[x][y];
    int check =0;
    if(N ==1){
        cnt[tmp]++;
        return;
    }
    for(int i=x; i<x+N; i++){
        for(int j=y; j<y+N; j++){
            if(tmp == A[i][j]) {check++;}
            
        }
    }
    if(check == N*N){
        cnt[tmp]++;
        return;
    }
    
    cut(x,y,N/2);
    cut(x,y+N/2,N/2);
    cut(x+N/2,y+N/2,N/2);
    cut(x+N/2,y,N/2);
    
}
int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> A[i][j];
        }
    }
    cut(0,0,N);
    for(int i=0; i<2; i++){
        cout << cnt[i] << endl;

    }
    return 0;
}
