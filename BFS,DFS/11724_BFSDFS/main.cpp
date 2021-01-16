//
//  main.cpp
//  11724_BFSDFS
//
//  Created by 홍진석 on 2020/11/18.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
int cnt;
vector<pair<int,int>> v;
bool check[1001];

void dfs(int loc){
    check[loc] = true;
  
    for(int i=0; i<v.size(); i++){
        if(loc == v[i].first && check[v[i].second] == false){
            dfs(v[i].second);
        }
    }
}

int main() {
    int a,b;
    
    cin >> N >> M;
    
    for(int i=0; i<M; i++){
        cin >> a >> b;
        v.push_back(make_pair(a, b));
        v.push_back(make_pair(b, a));
    }
    
    for(int j=1; j<=N; j++){
        if(check[j] == false){
            dfs(j);
            cnt++;
        }
    }
    
    cout << cnt;
    return 0;
}
