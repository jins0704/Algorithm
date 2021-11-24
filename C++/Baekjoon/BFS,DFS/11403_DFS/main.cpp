//
//  main.cpp
//  11403_DFS
//
//  Created by 홍진석 on 2020/08/14.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>

using namespace std;
int edge[101][101];
int aa[101][101];
bool check[101];
int N;
int cnt;
void dfs(int start,int loc,int index){

    if(index >= N) return;
    
    for(int i=1; i<=N; i++){
        if(edge[loc][i]==1 && check[i]==false){
            check[i] =true;
            dfs(start,i,index+1);
            edge[start][i]=1;
        }
    }
}

int main() {
    int temp;
    scanf("%d",&N);
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            scanf("%d",&temp);
            edge[i][j] = temp;
        }
    }
    for(int q=1; q<=N; q++){
        dfs(q,q,0);
        for(int s=0; s<=N; s++){
            check[s] = false;
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cout << edge[i][j]<< " ";
        }
        cout << endl;
    }
   
    return 0;
}
