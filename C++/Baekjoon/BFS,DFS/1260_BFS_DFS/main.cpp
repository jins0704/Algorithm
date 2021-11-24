//
//  main.cpp
//  cccc
//
//  Created by 홍진석 on 2020/07/14.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <stack>
#define MAX 1001
//정점 번호가 적은 것부터 방문, 더이상 없을 시 종료. 연결간선표현
using namespace std;

queue<int> q;
int visit_dfs[MAX];
int visit_bfs[MAX];
int edge[MAX][MAX];
int n,m,v; // 정점, 간선, 시작번지

void dfs(int v){
    visit_dfs[v] = 1;
    cout << v << " ";
   
    for(int i=1; i<=n; i++){
        if(visit_dfs[i] == 0 && edge[v][i] == 1){
            dfs(i);
        }
    }
} //dfs

void bfs(int v){
    q.push(v);
    visit_bfs[v] = 1;

    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout << f << " ";
    
        for(int i=0; i<=n; i++){
            if(visit_bfs[i] ==0 && edge[f][i]==1){
                q.push(i);
                visit_bfs[i] = 1;
            }
        }
    }
} //bfs

int main() {
    cin >> n >> m >> v;
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        edge[x][y] = 1;
        edge[y][x] = 1;
    }
    
    dfs(v);
    cout << endl;
    bfs(v);
    
    
    return 0;
}
