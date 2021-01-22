//
//  main.cpp
//  1325_BFs
//
//  Created by 홍진석 on 2020/08/20.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

queue<int> qc;
vector<int> map[10001];

int N,M;
bool check[10001];
int arr[10001];
int maximum;

void hacking(int start){
    int cnt = 0;
    check[start] = true;
    qc.push(start);
    
    while(!qc.empty()){
        int f = qc.front();
        qc.pop();
        
        for(int i=0; i<map[f].size(); i++){
            int p = map[f].at(i);
            if(check[p]==false){
                qc.push(p);
                check[p] = true;
                cnt++;
            }
        }
    }
    if(cnt>=maximum){
        maximum = cnt;
    }
    arr[start]= cnt;
    
}
int main() {

    cin >> N >> M;
    
    int temp1, temp2=0;
    
    for(int i=0; i<M; i++){
        scanf("%d %d", &temp1, &temp2);
        map[temp2].push_back(temp1);
    }
    for(int i=1; i<=N; i++){
        hacking(i);

        for(int j =1; j<=N; j++){
            check[j] = false;
        }
    }
    for(int k=1; k<=N; k++){
        if(arr[k]==maximum){
            cout << k << " ";
        }
    }
    return 0;
}
