//
//  main.cpp
//  2178_BFS
//
//  Created by 홍진석 on 2020/07/14.
//  Copyright © 2020 홍진석. All rights reserved.
//
#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
bool check[101][101];

void shortest(int startx,int starty,int endx,int endy){
    queue<pair<int,int>> q;
    queue<int> qc;
    check[startx][starty]=true;
    
  
    q.push(make_pair(startx,starty));
    qc.push(1);
    
    while(!q.empty()){
        int fx = q.front().first;
        int fy = q.front().second;
        int cc = qc.front();
        
        qc.pop();
        q.pop();
        
        if(fx == endx && fy ==endy){
            cout << cc << endl;
            return;
        }
        if(check[fx-1][fy]==false && arr[fx-1][fy]==1 && fx-1>=1){
            check[fx-1][fy] = true;
            qc.push(cc+1);
            q.push(make_pair(fx-1, fy));
        }
        if(check[fx+1][fy]==false && arr[fx+1][fy]==1 &&fx+1 <=endx){
            check[fx+1][fy] = true;
           qc.push(cc+1);
            q.push(make_pair(fx+1, fy));
        }
        if(check[fx][fy-1]==false && arr[fx][fy-1]==1 && fy-1>=1){
            check[fx][fy-1] = true;
           qc.push(cc+1);
            q.push(make_pair(fx, fy-1));
        }
        if(check[fx][fy+1]==false && arr[fx][fy+1]==1 && fy+1 <=endy){
            check[fx][fy+1] = true;
         qc.push(cc+1);
            q.push(make_pair(fx, fy+1));
        }
    }
  
}
int main(){
    int N,M,n;
    cin >> N >> M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d",&n);
            arr[i][j] = n;
        }
    }
    
    shortest(1,1,N,M);
}

