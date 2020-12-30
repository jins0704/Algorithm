//
//  main.cpp
//  15650_BackTracking
//
//  Created by 홍진석 on 2020/07/28.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int N, M;
int arr[100];
bool visit[100];

void solution(int index){
    if(index == M){
        for(int i=0; i<M; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    for(int j=1; j<= N; j++){
        if(visit[j]==false){
            if(index>=1){
                if(arr[index-1]>j){
                    continue;
                }
            }
            visit[j] =true;
            arr[index]= j;
            solution(index+1);
            visit[j] =false;
        }
    }
}
int main() {
    cin >> N >> M;
    solution(0);
    
    return 0;
}
