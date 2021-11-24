//
//  main.cpp
//  2644_BFS
//
//  Created by 홍진석 on 2020/08/19.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;

queue<int> qc;

int n;
int m;
int edge[101][101];
int check[101];
int cnt;
void bfs(int start, int last){
   
    check[start] = true;
    qc.push(start);
    
    while(!qc.empty()){
        unsigned long qsize = qc.size();
        
          for(int j=0; j<qsize; j++){
            int f= qc.front();
                   qc.pop();
            for(int i=1; i<=n; i++){
                if(edge[f][i]==1 && check[i]==false){
                    qc.push(i);
                    if(i ==last){
                        cout << cnt+1;
                        return;
                    }
                    check[i] = true;
                }
            }
        }
        cnt++;
    }
    cout << -1;
}
int main() {
    int a,b;
    int temp1,temp2;
    scanf("%d",&n);
    
    scanf("%d %d",&a,&b);
    
    scanf("%d",&m);
    for(int i=0; i<m; i++){
        scanf("%d %d", &temp1, &temp2);
        edge[temp1][temp2] = 1;
        edge[temp2][temp1] = 1;
    }
    
    bfs(a,b);
    
    return 0;
}
