//
//  main.cpp
//  15651_BackTraking
//
//  Created by 홍진석 on 2020/08/12.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;
bool check[8];
int t;
int arr[8];
void practice2(int index, int end){
    if(index == end){
        for(int j =0; j<M;j++){
            cout << v[j] << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i=1; i<=N; i++){
        v.push_back(i);
        practice2(index+1,end);
        v.pop_back();
    }
}
void practice(int index, int end){
    if(index == end){
        for(int j =0; j<M;j++){
            cout << arr[j] << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i=1; i<=N; i++){
            arr[index]= i;
            practice(index+1,end);
        
    }
}
int main() {
    
    cin >> N >> M;
    //int temp;
    
    practice(0,M);
    practice2(0,M);
    
    return 0;
}
