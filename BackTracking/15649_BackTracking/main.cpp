//
//  main.cpp
//  15649_BackTracking
//
//  Created by 홍진석 on 2020/07/27.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int N,M;
int arr[9];
bool visit[9];

void BackTracking(int index){
   
    if(index == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    
    for(int i= 1; i<=N; i++){
        if(visit[i] == false){
            visit[i] = true;
            arr[index] = i;
            BackTracking(index+1);
            visit[i] = false;
            
        }
    }
    
}
int main() {
    cin >> N >> M;
    BackTracking(0);
    return 0;
}
