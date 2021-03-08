//
//  main.cpp
//  2206_BFS
//
//  Created by 홍진석 on 2021/03/08.
//

#include <iostream>
#include <queue>

using namespace std;

// 벽을 한개까지 부수는 것은 가능

int arr[1001][1001];
int check[1001][1001][2];
int N,M,n;

// 상하좌우 이동가능
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

queue<pair<pair<int, int>,int>> loc;

int sol;
bool finish;

void Move(){
    
    loc.push(make_pair(make_pair(1, 1),0));
    check[1][1][0] = true;
    
    // 최단경로는 시작, 끝 포함해서 센다
    sol ++;
    
    while(!loc.empty()){
        
        unsigned long lsize = loc.size();
        
        for(int i=0; i<lsize; i++){
            
            int fx = loc.front().first.first;
            int fy = loc.front().first.second;
            int chance = loc.front().second;
            
            loc.pop();
            
            if(fx == N && fy == M){
                finish = true;
                return;
            }
            
            for(int j=0; j<4; j++){
                int nx = fx + dx[j];
                int ny = fy + dy[j];
                
                if(nx >=1 && ny>=1 && nx <= N && ny <= M){
                    if(arr[nx][ny] == 0 ){
                        if(check[nx][ny][chance] == 0){
                            check[nx][ny][chance] = 1;
                            //cout << fx << " " << fy << " " << "-> " << nx << " " << ny << " 벽 안깨고 이동" << chance << endl;
                            loc.push(make_pair(make_pair(nx, ny),chance));
                        }
                    }
                    
                    if(arr[nx][ny] == 1 && chance == 0){
                        if(check[nx][ny][1] == 0){
                            check[nx][ny][1] = 1;
                            loc.push(make_pair(make_pair(nx, ny), chance+1));
                            //cout << fx << " " << fy << " " << "-> " <<nx << " " << ny << " 벽 깨고 이동" << endl;
                        }
                    }
                }
            }
        }
        
        sol ++;
    }
}

int main() {
    
    // NxM 행렬
    cin >> N >> M;
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            // 이동가능 : 0, 벽 : 1
            scanf("%1d",&n);
            arr[i][j] = n;
        }
    }
    
    Move();
    
    if(finish){
        cout << sol;
    }
    else{
        // 최단경로 구하기 불가능하면 -1
        cout << -1;
    }
    return 0;
}
