//
//  main.cpp
//  15652_BackTracking
//
//  Created by 홍진석 on 2020/08/13.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N,M;
vector<int> v;

void go(int index, int end){
    if(index == end){
        for(int j=0; j<end; j++){
            cout << v[j] << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i=1; i<=N; i++){
        if(index == 0 || v[index-1]<=i){
            v.push_back(i);
            go(index+1,end);
            v.pop_back();
        }
    }
}
int main() {
    cin >> N >> M;
    go(0,M);
    return 0;
}
