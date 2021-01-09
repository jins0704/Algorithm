//
//  main.cpp
//  1182_BruteForce
//
//  Created by 홍진석 on 2020/08/14.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[21];
int N,S;
int cnt;

void go(int index, int sum){
    if(N <= index){
        if(sum == S) cnt ++;
        return;
    }
    
    go(index+1, sum+arr[index]);
    go(index+1, sum );
}
int main() {
    scanf("%d %d",&N, &S);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
    }
    
    go(0,0);

    if(S ==0) cnt --;
    
    printf("%d",cnt);
}
