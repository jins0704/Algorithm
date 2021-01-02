//
//  main.cpp
//  1012_BFS_DFS
//
//  Created by 홍진석 on 2020/07/25.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

int A[51][51];
int dx[4] = { -1,1,0,0};
//상- -1,0 하- 1,0 좌 0,-1 우 0,1
void bfs(int y, int x){
    queue<pair<int,int>> q;
    
    int count = 0;
    
    for(int i=0; i<y; i++){
        for(int j=0; j<x; j++){
            
            if(A[i][j] == 1){
                q.push({i,j});
                A[i][j] = 0;
              
                while(!q.empty()){
                    int qy = q.front().first;
                    int qx = q.front().second;
                    q.pop();
                    
                    if(A[qy-1][j] == 1  && qy-1>=0 ){
                        A[qy-1][qx] = 0;
                        q.push({qy-1,qx});
                    }
                   if(A[qy+1][qx] == 1 && i+1<=y){
                        A[qy+1][qx] = 0;
                        q.push({qy+1,qx});
                    }
                    if(A[qy][qx-1] == 1 && j-1>=0){
                        A[qy][qx-1] = 0;
                        q.push({qy,qx-1});
                    }
                    if(A[qy][qx+1] == 1 && j+1 <= x){
                        A[qy][qx+1] = 0;
                        q.push({qy,qx+1});
                    }
                }
                count ++;
            }
        }
    }
     cout << count << endl;
}
int main() {
    int T,K,N,M;
    int x,y;
    
    cin >> T;
    while(T--){
        cin >> M >> N >> K;
        for(int i=0; i<K; i++){
            cin >> x >> y;
            A[y][x] = 1;
        }
        bfs(N,M);
        for(int z=0; z<51; z++){
            for(int q=0; q< 51; q++){
                A[z][q] = 0;
            }
        }
    }
    return 0;
}
