//
//  main.cpp
//  2606_BFS_DFS
//
//  Created by 홍진석 on 2020/07/20.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int edge[101][101];
bool visit[101];
bool visit_bfs[101];
int comN;

void dfs(int start){
    visit[start]= true;
    
    for(int i=1; i<=comN; i++ ){
        if(!visit[i] && edge[start][i]){
            dfs(i);
        }
    }
}
void bfs(int start){
    queue<int> q;
    q.push(start);
    visit_bfs[start] = true;
   
    while(!q.empty()){
        int f =q.front();
        q.pop();
        
        for(int i=1; i<=comN; i++){
            if(!visit_bfs[i] &&edge[f][i]==1){
                q.push(i);
                visit_bfs[i] =true;
            }
        }
    }
}
int main() {
    int m,x,y;
    cin >> comN;
    cin >> m;
    for(int i=1; i<=m; i++){
        cin >> x >> y;
        edge[x][y]=1;
        edge[y][x]=1;
    }
    dfs(1);
    int count=0;
    int count2 =0;
    for(int i=2; i<=comN; i++){
        if(visit[i]==1)
            count ++;
    }
    cout << count;
    
    bfs(1);

    printf("\n");
    for(int i=2; i<=comN; i++){
           if(visit_bfs[i]==1)
               count2 ++;
       }
    cout << count2;
    
    return 0;
}
