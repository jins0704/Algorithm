//
//  main.cpp
//  10819_BackTracking
//
//  Created by 홍진석 on 2020/11/20.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[9];
int permu[9];
bool check[9];
int m = -1000;

void backtracking(int len){
    if(len == N){
        int sum = 0;
        
        for(int i=0; i<len-1; i++){
            sum += abs(permu[i]-permu[i+1]);
        }
        if(sum > m) m = sum;
        return;
    }
    for(int k=0; k<N; k++){
        if(!check[k]){
            check[k] = true;
            permu[len] = arr[k];
            backtracking(len+1);
            check[k] = false;
        }
    }
}
int main() {
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    
    backtracking(0);
    cout << m;
    
    return 0;
}
