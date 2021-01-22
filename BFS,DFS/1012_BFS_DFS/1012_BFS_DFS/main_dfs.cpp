//
//  main.cpp
//  practice111
//
//  Created by 홍진석 on 2020/08/03.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;

int arr[51][51];
int check[51][51];
int N,M;
void dfs(int y, int x){
    check[y][x] = 1;
    cout << y << " "<< x << "들림" << endl;
    if(y-1>=0 && check[y-1][x]==0 && arr[y-1][x]==1){

        dfs(y-1,x);
    }
    if(y+1 <= N && check[y+1][x]==0&& arr[y+1][x]==1){

        dfs(y+1,x);
    }
    if(x-1>=0 && check[y][x-1]==0&& arr[y][x-1]==1){

        dfs(y,x-1);
    }
    if(x+1<=M && check[y][x+1]==0 && arr[y][x+1]==1){

        dfs(y,x+1);
    }
}
int main() {
    int T,K;
    int x,y;
    cin >> T;
    
    while(T--){
        cin >> M >> N >> K;
        for(int i=0; i<K; i++){
            cin >> x >> y;
            arr[y][x] =1;
        }
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        int cnt=0;
        for(int i =0; i<N; i++){
            for(int j=0; j<M; j++){
                if(check[i][j] ==0 && arr[i][j]==1){
                    dfs(i,j);
                    cout<< endl;
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        
        for(int z=0; z<51; z++){
            for(int q=0; q<51; q++){
                arr[z][q] = 0;
                check[z][q] = 0;
            }
        }
    }
    return 0;
}

