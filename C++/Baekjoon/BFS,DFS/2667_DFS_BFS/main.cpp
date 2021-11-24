//
//  main.cpp
//  2667_DFS_BFS
//
//  Created by 홍진석 on 2020/08/04.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <algorithm>

using namespace std;

int arr[26][26];
int check_DFS[26][26];
int danji;
int dan[1000];
int N;

void search(int x, int y){
   
    dan[danji]++;
    
    check_DFS[x][y] = 1;
    //cout << x <<" "<< y << "검사"<<endl;;
    if(x-1>=0 && check_DFS[x-1][y]==0 && arr[x-1][y]==1){
        search(x-1, y);
    }
    if(x+1<=N && check_DFS[x+1][y]==0 && arr[x+1][y]==1){
        search(x+1, y);
    }
    if(y-1>=0 && check_DFS[x][y-1]==0 && arr[x][y-1]==1){
        search(x, y-1);
    }
    if(y+1<=N && check_DFS[x][y+1]==0 && arr[x][y+1]==1){
        search(x, y+1);
    }
}
int main() {
    int n;
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        for(int j =0; j<N; j++){
            scanf("%1d",&n);
            arr[i][j] = n;
        }
    }
    for(int q=0; q<N; q++){
        for(int w =0; w<N; w++){
            if(check_DFS[q][w] == 0 && arr[q][w] == 1){
                search(q,w);
                danji++;
                //cout << endl;
            }
        }
    }
    cout << danji << endl;
    sort(dan,dan+danji);
    for(int i=0; i<danji; i++){
        cout <<dan[i] << endl;
    }
    
    
    
    return 0;
}
