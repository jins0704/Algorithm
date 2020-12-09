//
//  main.cpp
//  1018_BruteForce
//
//  Created by 홍진석 on 2020/08/08.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

char arr[51][51];

int checkmin(int x, int y){
    int mi=0;
    int mi2=0;
    
    char tmp;
    tmp = arr[x][y];
    
    for(int i = x; i< x+8; i++){
        for(int j=y; j< y+8; j++){
            if((i+j)%2==0 && tmp!=arr[i][j]){
                mi++;
            }
            if((i+j)%2==1 && tmp == arr[i][j]){
                mi++;
            }
        }
    }
    if(tmp == 'B') {tmp = 'W';}
    else tmp = 'B';
    for(int i = x; i< x+8; i++){
        for(int j=y; j< y+8; j++){
            if((i+j)%2==0 && tmp!=arr[i][j]){
                mi2++;
            }
            if((i+j)%2==1 && tmp == arr[i][j]){
                mi2++;
            }
        }
    }
    if(mi>mi2) return mi2;
    else return mi;
}

int main() {
    int N,M;
    cin >> N >> M;
    char c;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> c;
            arr[i][j] = c;
        }
    }
    
    int min = 100;
    
    for(int q = 0; q<= N-8; q++){
        for(int w = 0; w<= M-8; w++){
            if(min > checkmin(q,w)) min = checkmin(q,w);
        }
    }
    
    cout << min << endl;
    
    return 0;
}
