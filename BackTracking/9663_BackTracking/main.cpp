//
//  main.cpp
//  9663_BackTracking
//
//  Created by 홍진석 on 2020/09/17.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int N;
int arr[16][16];
int cnt;

bool check(int line, int i){
    for(int w=0; w< line; w++){
        if(arr[w][i]==1) return false;
    }
    int xx= line;
    int yy= i;
    while(xx>=0 && yy>=0){
        if(arr[xx][yy] ==1) return false;
        xx--;
        yy--;
    }
    xx= line;
    yy= i;
    while(xx>=0 && yy<N){
        if(arr[xx][yy]==1) return false;
        xx--;
        yy++;
    }
    return true;
}
void bt(int line){
    
 
    if(line == N){
       
        cnt ++;
        return;
    }
    else{
        for(int i=0; i<N; i++){
            if(check(line,i)){
                arr[line][i] =1;
                bt(line+1);
                arr[line][i] = 0;
            }
        }
    }
}

int main() {
    cin >> N;
    if(N==1){
        cout << 1;
        return 0;
    }
   
    bt(0);
    
    cout << cnt;
    return 0;
}
