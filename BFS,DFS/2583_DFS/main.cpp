//
//  main.cpp
//  2583_DFS
//
//  Created by 홍진석 on 2020/11/22.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M,K;
int arr[101][101];
int x1,y1,x2,y2;
int cnt;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int siz;

vector<int> v;

void dfs(int x, int y){
    for(int q=0; q<4; q++){
        int test = 0;
        int xx = x+dx[q];
        int yy = y+dy[q];
        
        if(xx>=0 && xx<N && yy>=0 && yy<M){
            if(arr[xx][yy] == 0){
                arr[xx][yy] = 1;
                siz ++;
                dfs(xx,yy);
                test++;
            }
        }
    }
    
}

int main() {

    cin >> M >> N >> K;
    
    while(K--){
        cin >> x1 >> y1 >> x2 >> y2;
        for(int i=x1; i<x2; i++){
            for(int j=y1; j<y2; j++){
                arr[i][j] = 1;
            }
        }
    }
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(arr[j][i]==0){
                siz = 1;
                arr[j][i] = 1;
                dfs(j,i);
                cnt++;
                v.push_back(siz);
            }
        }
    }
    cout << cnt << endl;
    sort(v.begin(),v.end());
    for(int s =0; s<v.size(); s++){
        cout << v[s] << " ";
    }
    return 0;
}
