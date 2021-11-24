//
//  main.cpp
//  7576_BFS
//
//  Created by 홍진석 on 2020/08/16.
//  Copyright © 2020 홍진석. All rights reserved.
//

#include <iostream>
#include <queue>
#include <utility>

using namespace std;
int N,M,zerocnt;
int day= -1;
int arr[1001][1001];

queue<pair<int,int>> qw;
int dy[4] ={-1,1,0,0};
int dx[4] ={0,0,1,-1};


void spread(){
    if(zerocnt==0){
        cout << 0 << endl;
        return ;
    }
    while(!qw.empty()){
        unsigned long dayloop = qw.size();
        
        for(int f =0; f<dayloop; f++){
            int y = qw.front().first;
            int x = qw.front().second;
            qw.pop();
            
            for(int i=0; i<4; i++){
                int cy = y+dy[i];
                int cx = x+dx[i];
                
                if(arr[cy][cx]==0 && cy>=0 &&cy<N && cx>=0 && cx<M){
                    qw.push(make_pair(cy,cx));
                    arr[cy][cx]=1;
                    zerocnt --;
                }
            }
        }
        day++;
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(arr[i][j] == 0) {
                cout << -1 << endl;
                return;
            }
        }
    }
    cout << day << endl;
    return;
}
int main() {
    int temp;
    scanf("%d %d", &M,&N);//입력
    
    //0인 개수 찾기, 배열에 값 넣기
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d",&temp);
            arr[i][j] = temp;
            if(temp ==0) zerocnt++;
        }
    }
    
    //1 위치 큐에 넣기
    for(int q=0; q<N; q++){
        for(int w=0; w<M; w++){
            if(arr[q][w]==1){
                qw.push(make_pair(q,w));
            }
        }
    }
    
    spread();
    
    return 0;
}
