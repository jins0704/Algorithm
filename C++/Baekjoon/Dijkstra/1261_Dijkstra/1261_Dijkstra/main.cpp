//
//  main.cpp
//  1261_Dijkstra
//
//  Created by 홍진석 on 2021/04/11.
//

#include <iostream>
#include <queue>

using namespace std;
//미로 N*M
//상하좌우로 이동 가능
//AOJ로 벽을 빈방으로 바꾸기 가능
//1,1에 있는 운영진이 N,M으로 이동하려면 벽을 최소 몇개 부숴야할까
//첫째줄 가로 M , 세로 N
//N개의 줄에 미로 상태 : 빈방 0, 벽 1

int N,M,n;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int arr[101][101];
bool check[101][101];

priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<>> pq;

int main() {
    cin >> M >> N;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            scanf("%1d",&n);
            arr[i][j] = n;
        }
    }
    
    pq.push(make_pair(0, make_pair(1, 1)));
    
    while (!pq.empty()) {
        int currentX = pq.top().second.first;
        int currentY = pq.top().second.second;
        int wallCnt = pq.top().first;
        
        pq.pop();
        
        if(check[currentX][currentY]){continue;}
        check[currentX][currentY] = true;
    
        if(currentX == N && currentY == M){
            cout << wallCnt;
            break;
        }

        for(int i=0; i<4; i++){
            int nextX = currentX + dx[i];
            int nextY = currentY + dy[i];
            
            if(nextX >=1 && nextX <=N && nextY >=1 && nextY<=M){
                if(!check[nextX][nextY]){
                
                    if(arr[nextX][nextY] == 1){
                        pq.push(make_pair(wallCnt+1, make_pair(nextX, nextY)));
                    }
                    else{
                        pq.push(make_pair(wallCnt, make_pair(nextX, nextY)));
                    }
                    
                }
            }
            
        }
    }
    return 0;
}
