//
//  main.cpp
//  11399_Greedy
//
//  Created by 홍진석 on 2020/08/19.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[1001];
int check[1001];
int N;
int minsum;
int minindex;

void greedy(int indextime,int index,int totaltime){
    if(index == N){
        printf("%d",totaltime);
        return;
    }
    minsum = 1000;
    for(int i=1; i<=N; i++){
        if(arr[i]<=minsum && check[i]==false){
            minsum = arr[i];
            minindex = i;
        }
    }
    check[minindex] = true;
    indextime += minsum;
    totaltime += indextime;
    greedy(indextime,index+1,totaltime);
}
int main() {
    scanf("%d", &N);
    for(int i=1; i<=N; i++){
        scanf("%d",&arr[i]);
    }
    greedy(0,0,0);
    return 0;
}
