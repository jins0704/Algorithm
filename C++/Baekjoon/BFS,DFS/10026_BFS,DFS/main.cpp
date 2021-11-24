//
//  main.cpp
//  10026_BFS_DFS
//
//  Created by 홍진석 on 2020/12/01.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

char arr[101][101];
int N;
int cnt1;
int cnt2;
bool check1[101][101];
bool check2[101][101];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int y, int x, char ch){
    for(int k=0; k<4; k++){
        int cy = y+dy[k];
        int cx = x+dx[k];
        
        if(arr[cy][cx]==ch){
            if(check1[cy][cx] == false){
                check1[cy][cx] = true;
                dfs(cy, cx, ch);
            }
        }
        
    }
}
void dfs2(int y, int x, char ch){
    for(int q=0; q<4; q++){
        int cy = y+dy[q];
        int cx = x+dx[q];
        
        if(ch == 'B'){
            if(arr[cy][cx]==ch){
                if(check2[cy][cx] == false){
                    check2[cy][cx] = true;
                    dfs2(cy, cx, ch);
                }
            }
        }
        if(ch == 'R' || ch == 'G'){
            if(arr[cy][cx]=='R' || arr[cy][cx] == 'G' ){
                if(check2[cy][cx] == false){
                    check2[cy][cx] = true;
                    dfs2(cy, cx, ch);
                }
            }
        }
    }
}
int main() {
    cin >> N;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> arr[i][j];
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(check1[i][j] == false){
                check1[i][j] = true;
                dfs(i,j,arr[i][j]);
                cnt1++;
            }
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(check2[i][j] == false){
                check2[i][j] = true;
                dfs2(i,j,arr[i][j]);
                cnt2++;
            }
        }
    }
    cout <<cnt1 << " "<< cnt2;
    return 0;
}
